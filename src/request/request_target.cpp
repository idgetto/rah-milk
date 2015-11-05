#include "request/request_target.h"
#include <iostream>

RequestTarget::RequestTarget(const string& path, 
                             const RequestMethod& method) :
                            _path{path},
                            _method{method} {
}

bool RequestTarget::matches(const RequestTarget& other) const {
    return _path == other._path && _method == other._method;
}
