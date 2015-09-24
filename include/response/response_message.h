#ifndef RESPONSE_MESSAGE_H
#define RESPONSE_MESSAGE_H

#include <memory>
#include <ostream>

#include "http_version.h"
#include "response/status_code.h"

using std::unique_ptr;
using std::ostream;

class ResponseMessage {
public:
    const StatusCode& getStatusCode() const;
    void setStatusCode(const StatusCode& statusCode);

    const HttpVersion& getHttpVersion() const;
    void setHttpVersion(const HttpVersion& httpVersion);
private:
    HttpVersion _httpVersion;
    StatusCode _statusCode;
};

ostream& operator<<(ostream& out, const ResponseMessage& resp);

#endif
