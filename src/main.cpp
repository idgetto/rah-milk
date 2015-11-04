#include <iostream>

#include "rah_milk_server.h"

int main() {
    RahMilkServer server;

    server.on("/", [] (const RequestMessage& req, ResponseMessage& res) {
        res.setStatusCode(StatusCode::OK_200);
    });

    server.listen(3000);
}
