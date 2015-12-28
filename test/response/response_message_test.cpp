#include "gtest/gtest.h"
#include "response/response_message.h"

TEST(ResponseMessage, constructor) {
    ResponseMessage msg;
}

TEST(ResponseMessage, toString) {
    ResponseMessage msg;
    msg.setStatusCode(StatusCode::OK_200);
    msg.setHttpVersion(HttpVersion("HTTP/1.1"));

    HeaderGroup headers;
    headers.add("User-Agent", "Isaac");
    headers.add("Connection", "keep-alive");
    msg.setHeaderGroup(headers);

    stringstream actual;
    actual << msg;

    stringstream expected;
    expected << "HTTP/1.1 200 OK\r\n"
             << "User-Agent: Isaac\r\n"
             << "Connection: keep-alive\r\n\r\n";
    EXPECT_EQ(expected.str(), actual.str());
}
