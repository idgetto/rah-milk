#include <stdexcept>

#include "gtest/gtest.h"
#include "header_group.h"

#include <sstream>

using std::invalid_argument;
using std::stringstream;

TEST(HeaderGroup, constructor) {
    HeaderGroup headers;
}

TEST(HeaderGroup, add) {
    HeaderGroup headers;
    headers.add("name", "value");
    headers.add("name", "other");
    headers.add("foo", "bar");
    headers.add("Connection", "keep-alive");

    EXPECT_THROW(headers.add("Set-Cookie", "a=b"), invalid_argument);
    EXPECT_EQ("value, other", headers.get("name"));
}

TEST(HeaderGroup, get) {
    HeaderGroup headers;
    headers.add("name", "value");
    headers.add("foo", "bar");
    headers.add("Connection", "keep-alive");

    EXPECT_EQ("bar", headers.get("foo"));
    EXPECT_THROW(headers.get("Origin"), invalid_argument);
}

TEST(HeaderGroup, remove) {
    HeaderGroup headers;
    headers.add("name", "value");
    headers.add("foo", "bar");
    headers.add("Connection", "keep-alive");

    EXPECT_EQ("keep-alive", headers.remove("Connection"));
    EXPECT_THROW(headers.remove("Connection"), invalid_argument);
    EXPECT_THROW(headers.get("Connection"), invalid_argument);

}

TEST(HeaderGroup, addCookie) {
    HeaderGroup headers;
    headers.addCookie("a=b");

    vector<string> cookies = { "a=b" };
    EXPECT_EQ(cookies, headers.getCookies());

    headers.addCookie("another");
    headers.addCookie("another");
    headers.addCookie("last=true");

    cookies = { "a=b", "another", "another", "last=true" };
    EXPECT_EQ(cookies, headers.getCookies());
}

TEST(HeaderGroup, getCookies) {
    vector<string> cookies;
    HeaderGroup headers;
    EXPECT_EQ(cookies, headers.getCookies());

    headers.addCookie("a=b");
    cookies = { "a=b" };
    EXPECT_EQ(cookies, headers.getCookies());

    headers.addCookie("another");
    headers.addCookie("another");
    headers.addCookie("last=true");
    cookies = { "a=b", "another", "another", "last=true" };
    EXPECT_EQ(cookies, headers.getCookies());
}

TEST(HeaderGroup, clearCookies) {
    HeaderGroup headers;

    headers.addCookie("a=b");
    headers.addCookie("another");
    headers.addCookie("another");
    headers.addCookie("last=true");

    vector<string> cookies = { "a=b", "another", "another", "last=true" };
    EXPECT_EQ(cookies, headers.getCookies());

    headers.clearCookies();
    cookies.clear();
    EXPECT_EQ(cookies, headers.getCookies());
}

TEST(HeaderGroup, toString) {
    HeaderGroup headers;

    stringstream ss;

    headers.add("name", "value");
    ss << "name: value";
    ss << "\r\n";

    headers.add("foo", "bar");
    ss << "foo: bar";
    ss << "\r\n";

    headers.add("Connection", "keep-alive");
    ss << "Connection: keep-alive";
    ss << "\r\n";

    headers.addCookie("a=b");
    ss << "Set-Cookie: a=b";
    ss << "\r\n";

    headers.addCookie("another");
    ss << "Set-Cookie: another";
    ss << "\r\n";

    headers.addCookie("another");
    ss << "Set-Cookie: another";
    ss << "\r\n";
    
    headers.addCookie("last=true");
    ss << "Set-Cookie: last=true";
    ss << "\r\n";

    string expected = ss.str();

    stringstream hs;
    hs << headers;
    string actual = hs.str();
    
    EXPECT_EQ(expected, actual);
}
