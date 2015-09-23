#include "gtest/gtest.h"
#include "response/status_code.h"

TEST(StatusCode, getNumber) {
    StatusCode status = StatusCode::OK_200;
    EXPECT_EQ(200, status.getNumber());

    status = StatusCode::CONTINUE_100;
    EXPECT_EQ(100, status.getNumber());

    status = StatusCode::UNAUTHORIZED_401;
    EXPECT_EQ(401, status.getNumber());
}

TEST(StatusCode, getReason) {
    StatusCode status = StatusCode::OK_200;
    EXPECT_EQ("OK", status.getReason());

    status = StatusCode::CONTINUE_100;
    EXPECT_EQ("Continue", status.getReason());

    status = StatusCode::UNAUTHORIZED_401;
    EXPECT_EQ("Unauthorized", status.getReason());
}
