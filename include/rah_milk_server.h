#ifndef RAH_MILK_SERVER_H
#define RAH_MILK_SERVER_H

#include <string>
#include <functional>

#include "request/request_message.h"
#include "response/response_message.h"

using std::string;
using std::function;

class RahMilkServer {
    public:
        void listen(unsigned short port);

        using action_type = function<void(
                                const RequestMessage&, 
                                ResponseMessage&
                            )>;
        void on(const string& path, action_type action);
};

#endif
