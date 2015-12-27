#include "rah_milk_server.h"
#include <iostream>
#include <string>

void RahMilkServer::listen(unsigned short port) {
    _port = port;

    _server.addListener(this);
    _server.listen(port);
}

void RahMilkServer::on(const string& path,
                       const RequestMethod& method,
                       const RequestAction& action) {
    RequestTarget target(path, method);
    _router.connect(target, action);
}

void RahMilkServer::onHttpRequest(int fd) const {
    std::string msg = "Hello, World!";
    send(fd, msg.c_str(), msg.size(), 0);
    close(fd);
}
