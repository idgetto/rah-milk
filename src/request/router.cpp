#include <stdexcept>

#include "request/router.h"

using std::end;
using std::invalid_argument;

void Router::connect(const RequestTarget target, RequestAction action) {
    if (routes.find(target) != end(routes)) {
        throw invalid_argument("Routes must have unique targets");
    }
    routes.emplace(target, action);
}

void Router::disconnect(const RequestTarget target) {
    if (routes.find(target) == end(routes)) {
        throw invalid_argument("Could not find route to disconnect");
    }
}

Route Router::findRoute(const RequestTarget& target) const {
    if (routes.find(target) == end(routes)) {
        throw invalid_argument("Could not find route");
    }
    RequestAction action = routes.at(target);
    return Route(target, action); 
}
