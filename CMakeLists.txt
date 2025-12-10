cmake_minimum_required(VERSION 3.14)
project(play VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    main
    src/main.cpp
)

target_include_directories(
    main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)




include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    hello_test
    test/test.cpp
)

target_link_libraries(
    hello_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
