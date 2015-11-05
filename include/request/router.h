#ifndef ROUTER_H
#define ROUTER_H

#include <functional>

#incldue "request/route.h"

using std::function;

class Router {
    public:
        using action_type = function<void(
                                const RequestMessage&, 
                                ResponseMessage&
                            )>;
        void connect(const RequestTarget& target, action_type action);
        void disconnect(const RequestTarget& target);
        Route findRoute(const RequestTarget& target);
};

#endif
