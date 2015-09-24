#include "gtest/gtest.h"
#include "response/response_message.h"

TEST(ResponseMessage, constructor) {
    ResponseMessage msg;
}

TEST(ResponseMessage, toString) {
    ResponseMessage msg;
    msg.setStatusCode(StatusCode::OK_200);
    msg.setHttpVersion(HttpVersion("HTTP/1.1"));

    stringstream ss;
    ss << msg;
    EXPECT_EQ("HTTP/1.1 200 OK\r\n", ss.str());
}
