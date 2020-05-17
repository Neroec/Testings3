#include <gtest/gtest.h>

#include "GameManager.h"

TEST(CoinsCollision_positive, single_touched)
{
    int old[] = {
        3, 10, 10,
      10, 10, 100, 100, 200, 200
    };
    
    vector<int> oldCoins (old, old + sizeof(old) / sizeof(int));
      
    int ne[] = {
        2, 10, 10,
        100, 100, 200, 200
    };

    vector<int> newCoins (ne, ne + sizeof(ne) / sizeof(int));  

    EXPECT_EQ(coinsCollision(10, 10, 1, 1, oldCoins), newCoins);
}

TEST(CoinsCollision_positive, multiple_touched_nearby)
{
    int old[] = {
        3, 10, 10,
      10, 10, 10, 20, 200, 200
    };
    
    vector<int> oldCoins (old, old + sizeof(old) / sizeof(int));
        
    int ne[] = {
        1, 10, 10,
        200, 200
    };

    vector<int> newCoins (ne, ne + sizeof(ne) / sizeof(int));  

    EXPECT_EQ(coinsCollision(10, 10, 5, 15, oldCoins), newCoins);
}

TEST(CoinsCollision_positive, multiple_touched_apart)
{
    int old[] = {
        3, 10, 10,
      10, 10, 200, 200, 10, 20
    };
    
    vector<int> oldCoins (old, old + sizeof(old) / sizeof(int)); 
        
    int ne[] = {
        1, 10, 10,
        200, 200
    };

    vector<int> newCoins (ne, ne + sizeof(ne) / sizeof(int));  

    EXPECT_EQ(coinsCollision(10, 10, 5, 15, oldCoins), newCoins);
}

TEST(CoinsCollision_positive, not_touched)
{
    int old[] = {
        3, 10, 10,
      10, 10, 100, 100, 200, 200
    };
    
    vector<int> oldCoins (old, old + sizeof(old) / sizeof(int)); 
        
    int ne[] = {
        3, 10, 10,
        10, 10, 100, 100, 200, 200
    };

    vector<int> newCoins (ne, ne + sizeof(ne) / sizeof(int));   

    EXPECT_EQ(coinsCollision(10, 10, 0, 0, oldCoins), newCoins);
}

TEST(CoinsCollision_negative, sizes_not_more_0)
{
    int old[] = {
        3, -10, -10,
      10, 10, 100, 100, 200, 200
    };
    
    vector<int> oldCoins (old, old + sizeof(old) / sizeof(int));
        
    int ne[] = {
        3, -10, -10,
        10, 10, 100, 100, 200, 200
      };

    vector<int> newCoins (ne, ne + sizeof(ne) / sizeof(int));
        
    EXPECT_EQ(coinsCollision(-10, -10, 5, 15, oldCoins), newCoins);
}
