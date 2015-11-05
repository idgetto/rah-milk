#include <stdexcept>

#include "request/request_method.h"

RequestMethod::RequestMethod(const string& str) :
    _str(str) {}

RequestMethod RequestMethod::fromString(const string& method) {        
    if (method == RequestMethod::OPTIONS_STR) {
        return RequestMethod::OPTIONS;
    } else if (method == RequestMethod::GET_STR) {
        return RequestMethod::GET;
    } else if (method == RequestMethod::HEAD_STR) {
        return RequestMethod::HEAD;
    } else if (method == RequestMethod::POST_STR) {
        return RequestMethod::POST;
    } else if (method == RequestMethod::PUT_STR) {
        return RequestMethod::PUT;
    } else if (method == RequestMethod::DELETE_STR) {
        return RequestMethod::DELETE;
    } else if (method == RequestMethod::TRACE_STR) {
        return RequestMethod::TRACE;
    } else if (method == RequestMethod::CONNECT_STR) {
        return RequestMethod::CONNECT;
    } else {
        throw std::invalid_argument("Unknown HTTP method \"" + method + "\"");
    }
}

const string& RequestMethod::getStr() const {
    return _str;
}

const string RequestMethod::GET_STR = "GET";
const string RequestMethod::HEAD_STR = "HEAD";
const string RequestMethod::POST_STR = "POST";
const string RequestMethod::PUT_STR = "PUT";
const string RequestMethod::DELETE_STR = "DELETE";
const string RequestMethod::TRACE_STR = "TRACE";
const string RequestMethod::OPTIONS_STR = "OPTIONS";
const string RequestMethod::CONNECT_STR = "CONNECT";

const RequestMethod RequestMethod::GET(GET_STR);
const RequestMethod RequestMethod::HEAD(HEAD_STR);
const RequestMethod RequestMethod::POST(POST_STR);
const RequestMethod RequestMethod::PUT(PUT_STR);
const RequestMethod RequestMethod::DELETE(DELETE_STR);
const RequestMethod RequestMethod::TRACE(TRACE_STR);
const RequestMethod RequestMethod::OPTIONS(OPTIONS_STR);
const RequestMethod RequestMethod::CONNECT(CONNECT_STR);

ostream& operator<<(ostream& out, const RequestMethod& requestMethod) {
    out << requestMethod.getStr();
    return out;
}

bool operator==(const RequestMethod& a, const RequestMethod& b) {
    return a.getStr() == b.getStr();
}
