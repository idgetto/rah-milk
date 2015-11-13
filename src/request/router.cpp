#include <stdexcept>

#include "request/router.h"

using std::end;
using std::invalid_argument;

void Router::connect(const RequestTarget target, RequestAction action) {
    if (routes.find(target) != end(routes)) {
        throw invalid_argument("Routes must have unique targets");
    }
}

void Router::disconnect(const RequestTarget target) {
}

Route Router::findRoute(const RequestTarget& target) const {
}
