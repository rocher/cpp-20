import hello;

#include <gtest/gtest.h>
#include <string>

TEST(HelloTest, BasicAssertions) {
    const std::string hello_world ("Hello world\n");
    const std::string say_hello (hello::say_hello());
    EXPECT_EQ(hello_world, say_hello);
    EXPECT_EQ(6*6, 36);
}
