#include "request/request_message.h"

unique_ptr<RequestMessage> RequestMessage::fromRequestString(const string& req) {        
    return unique_ptr<RequestMessage>(new RequestMessage());
}
