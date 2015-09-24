#ifndef STATUS_CODE_H
#define STATUS_CODE_H

#include <string>

using std::string;

class StatusCode {
private:
    unsigned _number;
    string _reason;

public:
    StatusCode() {}
    StatusCode(unsigned number, const string& reason);

    unsigned getNumber() const;
    const string& getReason() const;

    static const StatusCode CONTINUE_100;
    static const StatusCode SWITCHING_PROTOCOLS_101;
    static const StatusCode OK_200;
    static const StatusCode CREATED_201;
    static const StatusCode ACCEPTED_202;
    static const StatusCode NON_AUTHORITATIVE_INFORMATION_203;
    static const StatusCode NO_CONTENT_204;
    static const StatusCode RESET_CONTENT_205;
    static const StatusCode PARTIAL_CONTENT_206;
    static const StatusCode MULTIPLE_CHOICES_300;
    static const StatusCode MOVED_PERMANENTLY_301;
    static const StatusCode FOUND_302;
    static const StatusCode SEE_OTHER_303;
    static const StatusCode NOT_MODIFIED_304;
    static const StatusCode USE_PROXY_305;
    static const StatusCode TEMPORARY_REDIRECT_307;
    static const StatusCode BAD_REQUEST_400;
    static const StatusCode UNAUTHORIZED_401;
    static const StatusCode PAYMENT_REQUIRED_402;
    static const StatusCode FORBIDDEN_403;
    static const StatusCode NOT_FOUND_404;
    static const StatusCode METHOD_NOT_ALLOWED_405;
    static const StatusCode NOT_ACCEPTABLE_406;
    static const StatusCode PROXY_AUTHENTICATION_REQUIRED_407;
    static const StatusCode REQUEST_TIME_OUT_408;
    static const StatusCode CONFLICT_409;
    static const StatusCode GONE_410;
    static const StatusCode LENGTH_REQUIRED_411;
    static const StatusCode PRECONDITION_FAILED_412;
    static const StatusCode REQUEST_ENTITY_TOO_LARGE_413;
    static const StatusCode REQUEST_URI_TOO_LARGE_414;
    static const StatusCode UNSUPPORTED_MEDIA_TYPE_415;
    static const StatusCode REQUEST_RANGE_NOT_SATISFIABLE_416;
    static const StatusCode EXPECTATION_FAILED_417;
    static const StatusCode INTERNAL_SERVER_ERROR_500;
    static const StatusCode NOT_IMPLEMENTED_501;
    static const StatusCode BAD_GATEWAY_502;
    static const StatusCode SERVICE_UNAVAILABLE_503;
    static const StatusCode GATEWAY_TIMEOUT_504;
    static const StatusCode HTTP_VERSION_NOT_SUPPORTED_505;
};

#endif
