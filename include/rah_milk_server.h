#ifndef RAH_MILK_SERVER_H
#define RAH_MILK_SERVER_H

#include <string>

#include "request/request_message.h"
#include "response/response_message.h"
#include "request/request_target.h"
#include "request/request_action.h"
#include "request/router.h"
#include "thread_pool.h"
#include "basic_http_server.h"
#include "i_http_request_listener.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

using std::string;
using std::function;

class RahMilkServer : public IHttpRequestListener {
    public:
        void listen(unsigned short port);

        void on(const string& path,
                const RequestMethod& method,
                const RequestAction& action);

        void onHttpRequest(int fd);

    private:
        BasicHttpServer _server;
        unsigned short _port;
        Router _router;
        ThreadPool _threadPool;
};

#endif
