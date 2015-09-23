#include "gtest/gtest.h"
#include "http_version.h"
#include "invalid_http_version_exception.h"

TEST(HttpVersion, constructor) {
    HttpVersion version("HTTP/1.1");
    EXPECT_EQ(1, version.getMajorVersion());
    EXPECT_EQ(1, version.getMinorVersion());

    HttpVersion http("HTTP/4.8");
    EXPECT_EQ(4, http.getMajorVersion());
    EXPECT_EQ(8, http.getMinorVersion());

    EXPECT_THROW(HttpVersion("HTTP/12.4"), InvalidHttpVersionException);
    EXPECT_THROW(HttpVersion("HTTP/1.13"), InvalidHttpVersionException);
    EXPECT_THROW(HttpVersion("1.2"), InvalidHttpVersionException);
}
