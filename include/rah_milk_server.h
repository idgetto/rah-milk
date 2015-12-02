#ifndef RAH_MILK_SERVER_H
#define RAH_MILK_SERVER_H

#include <string>

#include "request/request_message.h"
#include "response/response_message.h"
#include "request/request_target.h"
#include "request/request_action.h"
#include "request/router.h"
#include "thread_pool.h"

using std::string;
using std::function;

class RahMilkServer {
    public:
        void listen(unsigned short port);

        void on(const string& path,
                const RequestMethod& method,
                const RequestAction& action);

    private:
        unsigned short _port;
        Router _router;
        ThreadPool _threadPool;

        void _listen(unsigned short port);
};

#endif
