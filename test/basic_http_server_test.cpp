#include "gtest/gtest.h"
#include "basic_http_server.h"

class MockHttpRequestListener : public IHttpRequestListener {
    void onHttpRequest(int fd) {}
};

TEST(BasicHttpServer, addListener) {
    BasicHttpServer server;
    EXPECT_EQ(0, server.getListeners().size());

    auto l1 = MockHttpRequestListener();
    server.addListener(&l1);
    EXPECT_EQ(1, server.getListeners().size());

    auto l2 = MockHttpRequestListener();
    server.addListener(&l2);
    EXPECT_EQ(2, server.getListeners().size());
}

TEST(BasicHttpServer, removeListener) {
    BasicHttpServer server;
    EXPECT_EQ(0, server.getListeners().size());

    auto l1 = MockHttpRequestListener();
    server.addListener(&l1);
    EXPECT_EQ(1, server.getListeners().size());

    auto l2 = MockHttpRequestListener();
    server.addListener(&l2);
    EXPECT_EQ(2, server.getListeners().size());

    server.removeListener(&l2);
    EXPECT_EQ(1, server.getListeners().size());

    server.removeListener(&l1);
    EXPECT_EQ(0, server.getListeners().size());
}

TEST(BasicHttpServer, getListeners) {
    BasicHttpServer server;
    EXPECT_EQ(0, server.getListeners().size());

    auto l1 = MockHttpRequestListener();
    server.addListener(&l1);
    EXPECT_EQ(1, server.getListeners().size());

    auto l2 = MockHttpRequestListener();
    server.addListener(&l2);
    EXPECT_EQ(2, server.getListeners().size());
}

TEST(BasicHttpServer, notifyListeners) {
}
