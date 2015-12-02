cmake_minimum_required(VERSION 3.3)
project(rah_milk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(lib)
include_directories(include)
include_directories(rah-milk)

set(SOURCE_FILES
    include/request/request_action.h
    include/request/request_message.h
    include/request/request_method.h
    include/request/request_target.h
    include/request/route.h
    include/request/router.h
    include/response/response_message.h
    include/response/status_code.h
    include/test/first_fixture.h
    include/basic_regex.h
    include/header_group.h
    include/http_version.h
    include/invalid_http_version_exception.h
    include/rah_milk_server.h
    lib/libthreadpool.a
    src/request/request_action.cpp
    src/request/request_message.cpp
    src/request/request_method.cpp
    src/request/request_target.cpp
    src/request/route.cpp
    src/request/router.cpp
    src/response/response_message.cpp
    src/response/status_code.cpp
    src/basic_regex.cpp
    src/header_group.cpp
    src/http_version.cpp
    src/main.cpp
    src/rah_milk_server.cpp
    test/request/request_message_test.cpp
    test/request/request_method_test.cpp
    test/request/request_target_test.cpp
    test/request/router_test.cpp
    test/response/response_message_test.cpp
    test/response/status_code_test.cpp
    test/first_test.cpp
    test/header_group_test.cpp
    test/http_version_test.cpp
    Makefile)

add_executable(rah_milk ${SOURCE_FILES})