#include <gtest/gtest.h>

#include "GameManager.h"

TEST(YCollision_positive, touched)
{
    EXPECT_EQ(yCollision(10, 0, 10, 9), true);
}

TEST(YCollision_positive, not_touched)
{
    EXPECT_EQ(yCollision(10, 0, 10, 10), false);
}

TEST(YCollision_negative, height_not_more_0)
{
    EXPECT_EQ(xCollision(0, 0, 0, 10), false);
}
