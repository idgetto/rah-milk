#include "rah_milk_server.h"

void RahMilkServer::listen(unsigned short port) {
    _port = port;
    _listen(_port);
}

void RahMilkServer::on(const string& path,
                       const RequestMethod& method,
                       action_type action) {
    RequestTarget target(path, method);
    // routes.add(target, action);
}

void RahMilkServer::_listen(unsigned short port) {
    // create socket, bind to port, and accept connections
}
