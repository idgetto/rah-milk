#ifndef ROUTE_H
#define ROUTE_H

#include <functional>

#include "request/request_target.h"
#include "request/request_action.h"

using std::function;

class Route {
    public:
        Route();
        Route(RequestTarget target, RequestAction action) :
            _target{target}, _action{action} {}

        void setTarget(RequestTarget target);
        void setAction(RequestAction action);

        RequestTarget getTarget();
        RequestAction getAction();

    private:
        RequestTarget _target;
        RequestAction _action;
};

#endif
