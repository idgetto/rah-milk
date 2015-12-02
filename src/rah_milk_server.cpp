#include "rah_milk_server.h"
#include <iostream>

void RahMilkServer::listen(unsigned short port) {
    _port = port;
    _listen(_port);
}

void RahMilkServer::on(const string& path,
                       const RequestMethod& method,
                       const RequestAction& action) {
    RequestTarget target(path, method);
    _router.connect(target, action);
}

void RahMilkServer::_listen(unsigned short port) {
    // create socket, bind to port, and accept connections
}
