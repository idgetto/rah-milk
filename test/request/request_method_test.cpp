#include "gtest/gtest.h"
#include "request/request_method.h"

using std::unique_ptr;

TEST(RequestMethod, fromString) {
    unique_ptr<RequestMethod> method = RequestMethod::fromString("");
    EXPECT_NE(nullptr, method);
}
