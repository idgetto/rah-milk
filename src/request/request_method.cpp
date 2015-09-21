#include "request/request_method.h"

unique_ptr<RequestMethod> RequestMethod::fromString(const string& method) {        
    return unique_ptr<RequestMethod>(new RequestMethod());
}
