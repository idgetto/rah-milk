#include <stdexcept>

#include "gtest/gtest.h"
#include "request/request_method.h"

TEST(RequestMethod, fromString) {
    RequestMethod method = RequestMethod::fromString("GET");
    EXPECT_EQ(RequestMethod::GET, method);

    EXPECT_THROW(RequestMethod::fromString(""), std::invalid_argument);
    EXPECT_THROW(RequestMethod::fromString("get"), std::invalid_argument);
    EXPECT_THROW(RequestMethod::fromString("Put"), std::invalid_argument);
}
