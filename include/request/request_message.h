#ifndef REQUEST_MESSAGE_H
#define REQUEST_MESSAGE_H

#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

class RequestMessage {
public:
    static unique_ptr<RequestMessage> fromRequestString(const string& req);        
};

#endif
