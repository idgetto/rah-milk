#include "response/status_code.h"

StatusCode::StatusCode(unsigned number, const string& reason) :
    _number{number},
    _reason{reason} {}

unsigned StatusCode::getNumber() const {
    return _number;
}

const string& StatusCode::getReason() const {
    return _reason;
}

const StatusCode StatusCode::CONTINUE_100 = StatusCode(100, "Continue");
const StatusCode StatusCode::SWITCHING_PROTOCOLS_101 = StatusCode(101, "Switching PROTOCOLS");
const StatusCode StatusCode::OK_200 = StatusCode(200, "OK");
const StatusCode StatusCode::CREATED_201 = StatusCode(201, "Created");
const StatusCode StatusCode::ACCEPTED_202 = StatusCode(202, "Accepted");
const StatusCode StatusCode::NON_AUTHORITATIVE_INFORMATION_203 = StatusCode(203, "Non-Authoritative Information");
const StatusCode StatusCode::NO_CONTENT_204 = StatusCode(204, "No Content");
const StatusCode StatusCode::RESET_CONTENT_205 = StatusCode(205, "Reset Content");
const StatusCode StatusCode::PARTIAL_CONTENT_206 = StatusCode(206, "Partial Content");
const StatusCode StatusCode::MULTIPLE_CHOICES_300 = StatusCode(300, "Multiple Choices");
const StatusCode StatusCode::MOVED_PERMANENTLY_301 = StatusCode(301, "Moved Permanently");
const StatusCode StatusCode::FOUND_302 = StatusCode(302, "Found");
const StatusCode StatusCode::SEE_OTHER_303 = StatusCode(303, "See Other");
const StatusCode StatusCode::NOT_MODIFIED_304 = StatusCode(304, "Not Modified");
const StatusCode StatusCode::USE_PROXY_305 = StatusCode(305, "Use Proxy");
const StatusCode StatusCode::TEMPORARY_REDIRECT_307 = StatusCode(307, "Temporary Redirect");
const StatusCode StatusCode::BAD_REQUEST_400 = StatusCode(400, "Bad Request");
const StatusCode StatusCode::UNAUTHORIZED_401 = StatusCode(401, "Unauthorized");
const StatusCode StatusCode::PAYMENT_REQUIRED_402 = StatusCode(402, "Payment Required");
const StatusCode StatusCode::FORBIDDEN_403 = StatusCode(403, "Forbidden");
const StatusCode StatusCode::NOT_FOUND_404 = StatusCode(404, "Not Found");
const StatusCode StatusCode::METHOD_NOT_ALLOWED_405 = StatusCode(405, "Method Not Allowed");
const StatusCode StatusCode::NOT_ACCEPTABLE_406 = StatusCode(406, "Not Acceptable");
const StatusCode StatusCode::PROXY_AUTHENTICATION_REQUIRED_407 = StatusCode(407, "Proxy Authentication Required");
const StatusCode StatusCode::REQUEST_TIME_OUT_408 = StatusCode(408, "Request Time-out");
const StatusCode StatusCode::CONFLICT_409 = StatusCode(409, "Conflict");
const StatusCode StatusCode::GONE_410 = StatusCode(410, "Gone");
const StatusCode StatusCode::LENGTH_REQUIRED_411 = StatusCode(411, "Length Required");
const StatusCode StatusCode::PRECONDITION_FAILED_412 = StatusCode(412, "Precondition Failed");
const StatusCode StatusCode::REQUEST_ENTITY_TOO_LARGE_413 = StatusCode(413, "Request Entity Too Large");
const StatusCode StatusCode::REQUEST_URI_TOO_LARGE_414 = StatusCode(414, "Request-URI Too Large");
const StatusCode StatusCode::UNSUPPORTED_MEDIA_TYPE_415 = StatusCode(415,  "Unsupported Media Type");
const StatusCode StatusCode::REQUEST_RANGE_NOT_SATISFIABLE_416 = StatusCode(416, "Request range not satisfiable");
const StatusCode StatusCode::EXPECTATION_FAILED_417 = StatusCode(417, "Expectation Failed");
const StatusCode StatusCode::INTERNAL_SERVER_ERROR_500 = StatusCode(500, "Internal Server Error");
const StatusCode StatusCode::NOT_IMPLEMENTED_501 = StatusCode(501, "Not Implemented");
const StatusCode StatusCode::BAD_GATEWAY_502 = StatusCode(502, "Bad Gateway");
const StatusCode StatusCode::SERVICE_UNAVAILABLE_503 = StatusCode(503, "Service Unavailable");
const StatusCode StatusCode::GATEWAY_TIMEOUT_504 = StatusCode(504, "Gateway Time-out");
const StatusCode StatusCode::HTTP_VERSION_NOT_SUPPORTED_505 = StatusCode(505, "HTTP Version not supported");

