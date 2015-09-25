#include "gtest/gtest.h"
#include "header_group.h"

TEST(HeaderGroup, constructor) {
    HeaderGroup headers;
}

TEST(HeaderGroup, add) {
    HeaderGroup headers;
    headers.add("name", "value");
    
    EXPECT_TRUE(headers.contains("name"));
    EXPECT_EQ(hpair("name", "value"), headers.getFirst("name"));
}

TEST(HeaderGroup, getFirst) {
    HeaderGroup headers;
    headers.add("foo", "bar");
    headers.add("foo", "asdf");

    EXPECT_EQ(hpair("foo", "bar"), headers.getFirst("foo"));
}

TEST(HeaderGroup, getLast) {
    HeaderGroup headers;
    headers.add("foo", "bar");
    headers.add("foo", "asdf");

    EXPECT_EQ(hpair("foo", "asdf"), headers.getLast("foo"));
}

TEST(HeaderGroup, getAll) {
    HeaderGroup headers;
    headers.add("foo", "bar");
    headers.add("foo", "asdf");

    vector<hpair> v  = { hpair("foo", "bar"), hpair("foo", "asdf") };
    EXPECT_EQ(v, headers.getAll("foo"));
}

TEST(HeaderGroup, removeFirst) {
    HeaderGroup headers;
    headers.add("foo", "bar");
    headers.add("foo", "asdf");

    EXPECT_EQ(hpair("foo", "bar"), headers.removeFirst("foo"));
    EXPECT_EQ(1, headers.count("foo"));
    EXPECT_EQ(hpair("foo", "asdf"), headers.getFirst("foo"));
}

TEST(HeaderGroup, removeLast) {
    HeaderGroup headers;
    headers.add("foo", "bar");
    headers.add("foo", "asdf");

    EXPECT_EQ(hpair("foo", "asdf"), headers.removeLast("foo"));
    EXPECT_EQ(1, headers.count("foo"));
    EXPECT_EQ(hpair("foo", "bar"), headers.getFirst("foo"));
}

TEST(HeaderGroup, removeAll) {
    HeaderGroup headers;
    headers.add("foo", "bar");
    headers.add("foo", "asdf");

    vector<hpair> v = { hpair("foo", "bar"), hpair("foo", "asdf") };
    EXPECT_EQ(v, headers.removeAll("foo"));
    EXPECT_FALSE(headers.contains("foo"));
}
