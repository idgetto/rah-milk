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

HeaderGroup& ResponseMessage::getHeaderGroup() {
    return _headerGroup;
}

const HeaderGroup& ResponseMessage::getHeaderGroup() const {
    return _headerGroup;
}

void ResponseMessage::setHeaderGroup(const HeaderGroup& headerGroup) {
    _headerGroup = headerGroup;
}

ostream& operator<<(ostream& out, const ResponseMessage& resp) {
    stringstream ss;

    // add status-line
    ss << resp.getHttpVersion() << " "
       << resp.getStatusCode().getNumber() << " "
       << resp.getStatusCode().getReason() << "\r\n";

    // add the headers
    ss << resp.getHeaderGroup();

    return out << ss.str();
}
