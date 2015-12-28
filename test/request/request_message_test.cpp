#include "gtest/gtest.h"
#include "request/request_message.h"

using std::unique_ptr;

TEST(RequestMessage, fromString) {
    unique_ptr<RequestMessage> req = RequestMessage::fromString("");
    EXPECT_NE(nullptr, req);
}
