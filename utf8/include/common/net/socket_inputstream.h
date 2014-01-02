#ifndef PAP_COMMON_NET_SOCKET_INPUTSTREAM_H_
#define PAP_COMMON_NET_SOCKET_INPUTSTREAM_H_

#include "common/net/config.h"
#include "common/lib/vnet/vnet.hpp"
#include "common/net/socket.h"
#include "common/net/packet.h"

namespace pap_common_net {

class SocketInputStream {

 public: //construct and destruct
   SocketInputStream(
       Socket* socket, 
       uint32_t bufferlength = SOCKETINPUT_BUFFERSIZE_DEFAULT, 
       uint32_t bufferlength_max = SOCKETINPUT_DISCONNECT_MAXSIZE);
   virtual ~SocketInputStream();
   
 public:
   uint32_t read(char* buffer, uint32_t length);
   bool readpacket(Packet* packet);
   bool peek(char* buffer, uint32_t length);
   bool skip(uint32_t length);
   uint32_t fill();
   void init();
   bool resize(int32_t size);
   uint32_t reallength();
   bool isempty();
   void cleanup();
   void setkey(unsigned char const* key);
   int32_t get_keylength();

 private:
   Socket* socket_;
   struct packet_t* packet_;
   struct endecode_param_t* endecode_param_;

};

};

#endif //PAP_COMMON_NET_SOCKET_INPUTSTREAM_H_
