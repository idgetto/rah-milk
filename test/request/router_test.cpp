#include "gtest/gtest.h"
#include "request/router.h"

TEST(Router, connect) {
    Router router;

    RequestTarget target("/", RequestMethod::GET);
    auto action = RequestAction([] (const RequestMessage& req, ResponseMessage& res) {
        res.setStatusCode(StatusCode::OK_200);
    });

    router.connect(target, action);
}

TEST(Router, connectSame) {
    Router router;

    RequestTarget target("/", RequestMethod::GET);
    auto action = RequestAction([] (const RequestMessage& req, ResponseMessage& res) {
        res.setStatusCode(StatusCode::OK_200);
    });

    router.connect(target, action);
    EXPECT_THROW(router.connect(target, action), std::invalid_argument);
}

TEST(Router, disconnect) {
    Router router;

    RequestTarget target("/", RequestMethod::GET);
    auto action = RequestAction([] (const RequestMessage& req, ResponseMessage& res) {
        res.setStatusCode(StatusCode::OK_200);
    });

    router.connect(target, action);
    EXPECT_NO_THROW(router.disconnect(target));
}

TEST(Router, disconnectNone) {
    Router router;

    RequestTarget target("/", RequestMethod::GET);
    auto action = RequestAction([] (const RequestMessage& req, ResponseMessage& res) {
        res.setStatusCode(StatusCode::OK_200);
    });

    EXPECT_THROW(router.disconnect(target), std::invalid_argument);
}

TEST(Router, findRoute) {
    Router router;

    RequestTarget target("/", RequestMethod::GET);
    auto action = RequestAction([] (const RequestMessage& req, ResponseMessage& res) {
        res.setStatusCode(StatusCode::OK_200);
    });

    router.connect(target, action);
    
    Route route = router.findRoute(target);
    EXPECT_EQ(target, route.getTarget());
    EXPECT_EQ(action, route.getAction());
}
