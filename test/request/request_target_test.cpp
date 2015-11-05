#include "gtest/gtest.h"
#include "request/request_target.h"

TEST(RequestTarget, matchesSelf) {
    RequestTarget target("/", RequestMethod::GET);
    EXPECT_TRUE(target.matches(target));
}

TEST(RequestTarget, matchesCopy) {
    RequestTarget target("/", RequestMethod::GET);
    RequestTarget other(target);
    EXPECT_TRUE(target.matches(other));
}

TEST(RequestTarget, matchesSame) {
    RequestTarget target("/", RequestMethod::GET);
    RequestTarget other("/", RequestMethod::GET);
    EXPECT_TRUE(target.matches(other));
}

TEST(RequestTarget, doesNotMatch) {
    RequestTarget target("/", RequestMethod::GET);
    RequestTarget other("/", RequestMethod::POST);
    EXPECT_FALSE(target.matches(other));

    RequestTarget about("/about", RequestMethod::GET);
    RequestTarget login("/login", RequestMethod::GET);
    EXPECT_FALSE(about.matches(login));
}
