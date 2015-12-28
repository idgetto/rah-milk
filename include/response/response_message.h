#ifndef RESPONSE_MESSAGE_H
#define RESPONSE_MESSAGE_H

#include <memory>
#include <ostream>
#include <string>

#include "http_version.h"
#include "response/status_code.h"
#include "header_group.h"
#include "request/request_message.h"
#include "response/response_message.h"

using std::string;
using std::unique_ptr;
using std::ostream;

class ResponseMessage {
public:
    const string& getMessageBody() const;
    void setMessageBody(const string& body);

    const StatusCode& getStatusCode() const;
    void setStatusCode(const StatusCode& statusCode);

    const HttpVersion& getHttpVersion() const;
    void setHttpVersion(const HttpVersion& httpVersion);

    HeaderGroup& getHeaderGroup();
    const HeaderGroup& getHeaderGroup() const;
    void setHeaderGroup(const HeaderGroup& headerGroup);

private:
    string _body;
    HttpVersion _httpVersion;
    StatusCode _statusCode;
    HeaderGroup _headerGroup;
};

ostream& operator<<(ostream& out, const ResponseMessage& resp);

#endif
