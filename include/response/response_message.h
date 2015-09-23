#ifndef RESPONSE_MESSAGE_H
#define RESPONSE_MESSAGE_H

#include <memory>

#include "http_version.h"
#include "response/status_code.h"

using std::unique_ptr;

class ResponseMessage {
private:
    unique_ptr<HttpVersion> _httpVersion;
    unique_ptr<StatusCode> _statusCode;
};

#endif
