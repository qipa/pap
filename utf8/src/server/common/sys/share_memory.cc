#include "server/common/sys/share_memory.h"
#include "server/common/base/log.h"
#if defined(__LINUX__)
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#elif defined(__WINDOWS__)
#include <winbase.h>
#endif

namespace pap_common_sys {

namespace share_memory { 

//-- struct start
data_header_t::data_header_t() {
  __ENTER_FUNCTION
    key = 0;
    size = 0;
    version = 0;
  __LEAVE_FUNCTION
}

data_header_t::~data_header_t() {
  //do nothing
}
//struct end --

namespace api {

int32_t create(uint64_t key, uint32_t size) {
  __ENTER_FUNCTION
    int32_t handle;
#if defined(__LINUX__)
    int32_t handle = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666);
    pap_server_common_base::Log::save_log("share_memory",
                                          "[share memory][api](create) handle = %d, key = %"PRIu64" ,error: %d%s",
                                          handle, 
                                          key, 
                                          errno, 
                                          LF);
#elif defined(__WINDOWS__)
    char buffer[65];
    memset(buffer, '\0', sizeof(buffer));
    snprintf(buffer, sizeof(buffer) - 1, "%"PRIu64, key);
    int32_t handle = static_cast<int32_t>(CreateFileMapping(static_cast<HANDLE>(0xFFFFFFFFFFFFFFFF), 
                                                            NULL, 
                                                            PAGE_READWRITE, 
                                                            0, 
                                                            size, 
                                                            buffer));
#endif
    return handle;
  __LEAVE_FUNCTION
    return -1;
}

int32_t open(uint64_t key, uint32_t size) {
  __ENTER_FUNCTION
    int32_t handle;
#if defined(__LINUX__)
    handle = shmget(key, size, 0);
    pap_server_common_base::Log::save_log("share_memory", 
                                          "[share memory][api](open) handle = %d ,key = %"PRIu64" ,error: %d%s", 
                                          handle, 
                                          key, 
                                          errno, 
                                          LF);
    return handle;
#elif defined(__WINDOWS__)
    char buffer[65];
    memset(buffer, '\0', sizeof(buffer));
    snprintf(buffer, sizeof(buffer) - 1, "%"PRIu64, key);
    handle = OpenFileMapping(FILE_MAP_ALL_ACCESS, true, buffer);
#endif
    return handle;
  __LEAVE_FUNCTION
    return -1;
}

char* map(int32_t handle) {
  __ENTER_FUNCTION
    char* result;
#if defined(__LINUX__)
    result = static_cast<char*>(shmat(handle, 0, 0));
#elif defined(__WINDOWS__)
    result = static_cast<char*>(MapViewOfFile(handle, FILE_MAP_ALL_ACCESS, 0, 0, 0));
#endif
    return result;
  __LEAVE_FUNCTION
    return NULL;
}

void unmap(char* pointer) {
  __ENTER_FUNCTION
#if defined(__LINUX__)
    shmdt(pointer);
#elif defined(__WINDOWS__)
    UnmapViewOfFile(pointer);
#endif
  __LEAVE_FUNCTION
}

void close(int32_t handle) {
  __ENTER_FUNCTION
#if defined(__LINUX__)
    shmctl(handle, IPC_RMID, 0);
#elif defined(__WINDOWS__)
    CloseHandle(handle);
#endif
  __LEAVE_FUNCTION
}

} //namespace api


//-- class start
Base::Base() {
  __ENTER_FUNCTION
    data_pointer_ = NULL;
    handle_ = 0;
    size_ = 0;
    header_ = 0;
  __LEAVE_FUNCTION
}

Base::~Base() {
  //do nothing
}

bool Base::create(uint64_t key, int32_t size) {
  __ENTER_FUNCTION
    if (kCmdModelClearAll == cmd_model_) return false;
    handle_ = api::create(key, size);
    if (HANDLE_INVALID == handle_) {
      pap_server_common_base::Log::save_log("share_memory", 
                                            "[share memory][base](create) create failed! handle = %d,key = %"PRIu64" %s", 
                                            handle_, 
                                            key, 
                                            LF);
      return false;
    }
    header_ = api::map(handle_);
    if (header_) {
      data_pointer_ = header_ + sizeof(data_header_t);
      (static_cast<data_header_t*>(header_))->key = key;
      (static_cast<data_header_t*>(header_))->size = size;
      size_ = size;
      pap_server_common_base::Log::save_log("share_memory", 
                                            "[share memory][base](create) success! handle = %d ,key = %"PRIu64" %s", 
                                            handle_, 
                                            key, 
                                            LF);
      return true;
    }
    else {
      pap_server_common_base::Log::save_log("share_memory", 
                                            "[share memory][base](create) map failed! handle = %d ,key = %"PRIu64" %s", 
                                            handle_, 
                                            key,
                                            LF);
      return false;
    }
  __LEAVE_FUNCTION
    return false;
}

void Base::destory() {
  __ENTER_FUNCTION
    if (header_) {
      api::unmap(header_);
      header_ = NULL;
    }
    if (handle_) {
      api::close(handle_);
      handle_ = NULL;
    }
    size_ = 0;
  __LEAVE_FUNCTION
}

bool Base::attach(uint64_t key, uint32_t size) {
  __ENTER_FUNCTION
    handle_ = api::open(key, size);
    if (kCmdModelClearAll == cmd_model_) {
      destory();
      pap_server_common_base::Log::save_log("share_memory",
                                            "[share memory][base](attach) close memory, key = %"PRIu64" %s", 
                                            key, 
                                            LF);
      return false;
    }
    if (HANDLE_INVALID == handle_) {
      pap_server_common_base::Log::save_log("share_memory", 
                                            "[share memory][base](attach) create failed, key = %"PRIu64" %s", 
                                            key, 
                                            LF);
      return false;
    }
    header_ = api::map(handle_);
    if (header_) {
      data_pointer_ = header_ + sizeof(data_header_t);
      Assert((static_cast<data_header_t*>(header_))->key == key);
      Assert((static_cast<data_header_t*>(header_))->size == size)
      pap_server_common_base::Log::save_log("share_memory", 
                                            "[share memory][base](attach) success, key = %"PRIu64" %s", 
                                            key, 
                                            LF);
      return true;
    }
    else {
      pap_server_common_base::Log::save_log("share_memory", 
                                            "[share memory][base](attach) map failed, key = %"PRIu64" %s", 
                                            key, 
                                            LF);
      return false;
    }
  __LEAVE_FUNCTION
    return false;
}

char* Base::get_data_pointer() {
  __ENTER_FUNCTION
    return data_pointer_;
  __LEAVE_FUNCTION
    return NULL;
}

char* Base::get_data(uint32_t size, uint32_t index) {
  __ENTER_FUNCTION
    pap_common_sys::Assert(size > 0);
    pap_common_sys::Assert(size * index < size_);
    char* result;
    result = (size <= 0 || index > size_) ? NULL : data_pointer_ + size * index;
    return result;
  __LEAVE_FUNCTION
    return NULL;
}

uint32_t Base::get_size() {
  __ENTER_FUNCTION
    return size_;
  __LEAVE_FUNCTION
    return 0;
}

bool Base::dump(const char* filename) {
  __ENTER_FUNCTION
    pap_common_sys::Assert(filename);
    FILE* fp = fopen(filename, "wb");
    if (!fp) return false;
    fwrite(header_, 1, size_, fp);
    fclose(fp);
    return true;
  __LEAVE_FUNCTION
    return false;
}

bool Base::merge_from_file(const char* filename) {
  __ENTER_FUNCTION
    Assert(filename);
    FILE* fp = fopen(filename, "rb");
    if (!fp) return false;
    fseek(fp, 0L, SEEK_END);
    int32_t filelength = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    fread(header_, filelength, 1, fp);
    fclose(fp);
    return true;
  __LEAVE_FUNCTION
    return false;
}

void Base::set_head_version(uint32_t version) {
  __ENTER_FUNCTION
    (static_cast<data_header_t*>(header_))->version = version;
  __LEAVE_FUNCTION
}

uint32_t Base::get_head_version() {
  __ENTER_FUNCTION
    uint32_t version = (static_cast<data_header_t*>(header_))->version;
    return version;
  __LEAVE_FUNCTION
    return 0;
}

//class end --

} //namespace share_memory

} //namespace pap_common_sys