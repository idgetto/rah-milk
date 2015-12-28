#ifndef REQUEST_MESSAGE_H
#define REQUEST_MESSAGE_H

#include <string>
#include <memory>

#include "request/request_method.h"
#include "request/request_target.h"

using std::string;
using std::unique_ptr;

class RequestMessage {
public:
    static unique_ptr<RequestMessage> fromString(const string& req);

private:
    unique_ptr<RequestMethod> _requestMethod;
    unique_ptr<RequestTarget> _requestTarget;
};

#endif
