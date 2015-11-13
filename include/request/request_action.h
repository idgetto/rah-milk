#ifndef REQUEST_ACTION_H
#define REQUEST_ACTION_H

#include <functional>

#include "request/request_message.h"
#include "response/response_message.h"

class RequestAction;

template <>
struct std::hash<RequestAction>;

using std::function;
using std::size_t;

class RequestAction {
    public:
        using function_t = function<void(
                                const RequestMessage&,
                                ResponseMessage&
                            )>;
        RequestAction(function_t action);

        void operator()(const RequestMessage& req, ResponseMessage& res);
        bool operator==(const RequestAction& other) const;

        friend struct std::hash<RequestAction>;

    private:
        size_t _id;
        function_t _action;
        static size_t _classId;

        static size_t getId();
};

namespace std {
    template <>
    struct hash<RequestAction> {
        size_t operator()(const RequestAction& action) const {
            return action._id;
        }
    };
}

#endif
