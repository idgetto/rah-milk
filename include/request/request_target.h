#ifndef REQUEST_TARGET_H
#define REQUEST_TARGET_H

#include <string>

#include "request/request_method.h"

using std::string;

class RequestTarget;

template <>
struct std::hash<RequestTarget>;

class RequestTarget {
    public:
        RequestTarget(const string& path, 
                      const RequestMethod& method);
        bool matches(const RequestTarget& other) const;

        bool operator==(const RequestTarget& other) const;

        friend struct std::hash<RequestTarget>;

    private:
        string _path;
        RequestMethod _method;
};

namespace std {
    template <>
    struct hash<RequestTarget> {
        std::size_t operator()(const RequestTarget& target) const {
            std::size_t h1 = std::hash<string>()(target._path);
            std::size_t h2 = std::hash<string>()(target._method.getStr());
            return h1 ^ (h2 << 1);
        }
    };
}

#endif
