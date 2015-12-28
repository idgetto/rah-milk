#include "request/request_message.h"

unique_ptr<RequestMessage> RequestMessage::fromString(const string& req) {
    return unique_ptr<RequestMessage>(new RequestMessage());
}
