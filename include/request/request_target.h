#ifndef REQUEST_TARGET_H
#define REQUEST_TARGET_H

#include <string>

#include "request/request_method.h"

using std::string;

class RequestTarget {
    public:
        RequestTarget(const string& path, 
                      const RequestMethod& method);
        bool matches(const RequestTarget& other) const;

    private:
        string _path;
        RequestMethod _method;
};

#endif
