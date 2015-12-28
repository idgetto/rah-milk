#ifndef I_HTTP_REQUEST_LISTENER_H
#define I_HTTP_REQUEST_LISTENER_H

#include "request/request_message.h"

class IHttpRequestListener {
    public:
        virtual void onHttpRequest(int fd) = 0;
};

#endif
