#include <gtest/gtest.h>

#include "GameManager.h"

TEST(MarioStatus_positiv, moveRight1)
{
    EXPECT_EQ(marioStatus(1, 0, "StopRight"), "MoveRight");
}

TEST(MarioStatus_positiv, moveRight2)
{
    EXPECT_EQ(marioStatus(1, 0, "MoveRight"), "StopRight");
}

TEST(MarioStatus_positiv, moveLeft1)
{
    EXPECT_EQ(marioStatus(-1, 0, "StopLeft"), "MoveLeft");
}

TEST(MarioStatus_positiv, moveLeft2)
{
    EXPECT_EQ(marioStatus(-1, 0, "MoveLeft"), "StopLeft");
}

TEST(MarioStatus_positiv, stopRight)
{
    EXPECT_EQ(marioStatus(0, 0, "MoveRight"), "StopRight");
}

TEST(MarioStatus_positiv, stopLeft)
{
    EXPECT_EQ(marioStatus(0, 0, "MoveLeft"), "StopLeft");
}

TEST(MarioStatus_positiv, moveAirRight)
{
    EXPECT_EQ(marioStatus(1, 1, "StopRight"), "MoveRight");
}

TEST(MarioStatus_positiv, moveAirLeft)
{
    EXPECT_EQ(marioStatus(-1, 1, "StopLeft"), "MoveLeft");
}

TEST(MarioStatus_positiv, stopAirRight)
{
    EXPECT_EQ(marioStatus(0, 1, "StopRight"), "MoveRight");
}

TEST(MarioStatus_positiv, stopAirLeft)
{
    EXPECT_EQ(marioStatus(0, 1, "StopLeft"), "MoveLeft");
}

TEST(MarioStatus_negativ, incorrect_status)
{
    EXPECT_EQ(marioStatus(0, 0, "incorrect"), "StopRight");
}
