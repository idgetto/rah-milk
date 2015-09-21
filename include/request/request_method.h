#ifndef REQUEST_METHOD_H
#define REQUEST_METHOD_H

#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

class RequestMethod {
public:
    static unique_ptr<RequestMethod> fromString(const string& method);        
};

#endif
