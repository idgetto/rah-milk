#include "gtest/gtest.h"
#include "test/first_fixture.h"

TEST_F(FirstTest, Truth) {
    EXPECT_TRUE(1 == 1);
    EXPECT_FALSE(3 == 4);
}

TEST_F(FirstTest, Equality) {
    EXPECT_EQ(4, 4);
    EXPECT_EQ(nullptr, nullptr);

    int x = 12;
    EXPECT_NE(4, 5);
    EXPECT_NE(nullptr, &x);

    EXPECT_LT(1, 2);
    EXPECT_LE(3, 5);

    EXPECT_GT(8, 3);
    EXPECT_GE(6, 4);
}

TEST_F(FirstTest, CString) {
    EXPECT_STREQ("Hello", "Hello");

    char potato[] = "Potato";
    char dogs[] = "Dogs";
    EXPECT_STRNE(potato, dogs);
    EXPECT_STRNE(nullptr, "");

    EXPECT_STRCASEEQ("CAT", "Cat");
    EXPECT_STRCASENE("mouse", "rat");
}

TEST_F(FirstTest, Fixture) {
    ASSERT_EQ(5, x);
}
