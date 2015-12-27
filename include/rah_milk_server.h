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

using std::string;
using std::function;

class RahMilkServer : public IHttpRequestListener {
    public:
        void listen(unsigned short port);

        void on(const string& path,
                const RequestMethod& method,
                const RequestAction& action);

        void onHttpRequest(int fd) const;

    private:
        BasicHttpServer _server;
        unsigned short _port;
        Router _router;
        ThreadPool _threadPool;
};

#endif
