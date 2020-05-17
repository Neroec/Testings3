#include <gtest/gtest.h>

#include "GameManager.h"

TEST(CoinsCollision_positive, single_touched)
{
    vector<int> oldCoins = {
      3, 10, 10,
      10, 10, 100, 100, 200, 200
    };

    vector<int> newCoins = {
        2, 10, 10,
        100, 100, 200, 200
    };

    EXPECT_EQ(coinsCollision(10, 10, 1, 1, oldCoins), newCoins);
}

TEST(CoinsCollision_positive, multiple_touched_nearby)
{
    vector<int> oldCoins = {
      3, 10, 10,
      10, 10, 10, 20, 200, 200
    };

    vector<int> newCoins = {
        1, 10, 10,
        200, 200
    };

    EXPECT_EQ(coinsCollision(10, 10, 5, 15, oldCoins), newCoins);
}

TEST(CoinsCollision_positive, multiple_touched_apart)
{
    vector<int> oldCoins = {
      3, 10, 10,
      10, 10, 200, 200, 10, 20
    };

    vector<int> newCoins = {
        1, 10, 10,
        200, 200
    };

    EXPECT_EQ(coinsCollision(10, 10, 5, 15, oldCoins), newCoins);
}

TEST(CoinsCollision_positive, not_touched)
{
    vector<int> oldCoins = {
      3, 10, 10,
      10, 10, 100, 100, 200, 200
    };

    vector<int> newCoins = {
        3, 10, 10,
        10, 10, 100, 100, 200, 200
    };

    EXPECT_EQ(coinsCollision(10, 10, 0, 0, oldCoins), newCoins);
}

TEST(CoinsCollision_negative, sizes_not_more_0)
{
    vector<int> oldCoins = {
      3, -10, -10,
      10, 10, 100, 100, 200, 200
    };

    vector<int> newCoins = {
        3, -10, -10,
        10, 10, 100, 100, 200, 200
      };

    EXPECT_EQ(coinsCollision(-10, -10, 5, 15, oldCoins), newCoins);
}
