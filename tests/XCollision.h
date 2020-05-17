#include <gtest/gtest.h>

#include "GameManager.h"

TEST(XCollision_positive, touched)
{
    EXPECT_EQ(xCollision(10, 0, 10, 10), true);
}

TEST(XCollision_positive, not_touched)
{
    EXPECT_EQ(xCollision(10, 0, 10, 11), false);
}

TEST(XCollision_negative, width_not_more_0)
{
    EXPECT_EQ(xCollision(0, 0, 0, 10), false);
}

