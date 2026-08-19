#include "wcs/ping.hpp"

#include <gtest/gtest.h>

TEST(Ping, ReturnsPongForPing) {
    EXPECT_EQ(wcs::ping("ping"), "pong");
}

TEST(Ping, EchoesOtherMessages) {
    EXPECT_EQ(wcs::ping("hello"), "hello");
}
