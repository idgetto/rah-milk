#include "response/response_message.h"

const StatusCode& ResponseMessage::getStatusCode() const {
    return _statusCode;
}

void ResponseMessage::setStatusCode(const StatusCode& statusCode) {
    _statusCode = statusCode;
}

const HttpVersion& ResponseMessage::getHttpVersion() const {
    return _httpVersion;
}

void ResponseMessage::setHttpVersion(const HttpVersion& httpVersion) {
    _httpVersion = httpVersion;
}

ostream& operator<<(ostream& out, const ResponseMessage& resp) {
    stringstream ss;

    // add status-line
    ss << resp.getHttpVersion() << " "
       << resp.getStatusCode().getNumber() << " "
       << resp.getStatusCode().getReason() << "\r\n";

    return out << ss.str();
}
