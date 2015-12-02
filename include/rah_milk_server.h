#ifndef RAH_MILK_SERVER_H
#define RAH_MILK_SERVER_H

#include <string>

#include "request/request_message.h"
#include "response/response_message.h"
#include "request/request_target.h"
#include "request/request_action.h"
#include "request/router.h"
#include "thread_pool.h"

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

        void handleRequest(int fd);
        void _listen(unsigned short port);
        static void sigchld_handler(int s);
        void *get_in_addr(struct sockaddr *sa);
};

#endif
