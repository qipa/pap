#include "server/billing/connection/manager.h"
#include "server/billing/connection/pool.h"

namespace connection {

Manager::Manager() : pap_server_common_net::connection::Manager() {
  //do nothing
}

Manager::~Manager() {
  //do nothing
}

void Manager::cleanup() {
  pap_server_common_net::connection::Manager::cleanup();
}

bool Manager::heartbeat(uint32_t time) {
  __ENTER_FUNCTION
    bool result = false;
    result = pap_server_common_net::connection::heartbeat(time);
    return result;
  __LEAVE_FUNCTION
    return false;
}

bool Manager::add(pap_server_common_net::connection::Base* connection) {
  __ENTER_FUNCTION
    bool result = false;
    result = pap_server_common_net::connection::Manager::add(connection);
    return result;
  __LEAVE_FUNCTION
    return false;
}

bool Manager::add(int16_t id) {
  __ENTER_FUNCTION
    bool result = false;
    result = pap_server_common_net::connection::Manager::add(id);
    return result;
  __LEAVE_FUNCTION
    return false;
}

void Manager::remove(int16_t id) {
  __ENTER_FUNCTION
    Assert(count_ > 0);
    pap_server_common_net::connection::Base* connection = NULL;
    connection = g_connectionpool->get(id);
    if (NULL == connection) {
      Assert(false);
      return;
    }
    int16_t managerid = connection->get_managerid();

  __LEAVE_FUNCTION
}

} //namespace connection
