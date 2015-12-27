#ifndef BASIC_HTTP_SERVER_H
#define BASIC_HTTP_SERVER_H

#include <vector>
#include <sys/socket.h>

#include "i_http_request_listener.h"

using std::vector;

class BasicHttpServer {
    static constexpr int BACKLOG = 10;
    vector<const IHttpRequestListener *> _listeners;

    public:
        // port in range of 1-65535
        // https://en.wikipedia.org/wiki/Registered_port
        void listen(const unsigned short port);

        void addListener(const IHttpRequestListener *listener);
        void removeListener(const IHttpRequestListener *listener);
        vector<const IHttpRequestListener *> getListeners() const;

    private:
        void notifyListeners(int fd) const;
        void *get_in_addr(struct sockaddr *sa);
        static void sigchld_handler(int s);
};

#endif
