#ifndef ROUTER_H
#define ROUTER_H

#include <unordered_map>

#include "request/route.h"
#include "request/request_target.h"
#include "request/request_action.h"
#include "request/request_message.h"
#include "response/response_message.h"

using std::unordered_map;

class Router {
    public:
        void connect(const RequestTarget target, RequestAction action);
        void disconnect(const RequestTarget target);
        Route findRoute(const RequestTarget& target) const;

    private:
        unordered_map<RequestTarget, RequestAction> routes;
};

#endif
