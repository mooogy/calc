#include <gtest/gtest.h>

// See if GTest is working properly
TEST(Base, BasicAssertions) {

    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);

}
