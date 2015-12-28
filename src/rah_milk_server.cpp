#include <iostream>
#include <string>
#include <sstream>

#include "header_group.h"
#include "rah_milk_server.h"

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

void RahMilkServer::onHttpRequest(int fd) {
    _threadPool.post([this, fd] {
        string reqStr = readRequest(fd);

        auto req = RequestMessage::fromString(reqStr);
        ResponseMessage res;
        auto action = RequestAction(
            [] (const RequestMessage& req, ResponseMessage& res) {
                res.setStatusCode(StatusCode::OK_200);

                HeaderGroup headers;
                headers.add("rah", "milk");
                headers.addCookie("fake=true");

                res.setHeaderGroup(headers);

                string html = "<html><body><h1>Rah Milk</h1></body></html>";
                res.setMessageBody(html);
            }
        );

        action(*req, res);

        std::stringstream ss;
        ss << res;
        string resStr = ss.str();

        std::cout << resStr << "\n";
        send(fd, resStr.c_str(), resStr.size(), 0);
        close(fd);

        return 0;
    });
}

string RahMilkServer::readRequest(int fd) {
    char buf[REQUEST_SIZE];
    int res = recv(fd, buf, REQUEST_SIZE, 0);

    if (res <= 0) {
        fprintf(stderr, "recv: %d\n", res);
        exit(1);
    }

    std::stringstream ss;
    ss << buf;
    return ss.str();
}
