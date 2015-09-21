#include "gtest/gtest.h"
#include "request/request_message.h"

using std::unique_ptr;

TEST(RequestMessage, fromRequestString) {
    unique_ptr<RequestMessage> req = RequestMessage::fromRequestString("");
    EXPECT_NE(nullptr, req);
}
