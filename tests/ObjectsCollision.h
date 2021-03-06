#include <gtest/gtest.h>

#include "GameManager.h"

TEST(ObjectsCollision_positive, zero_yVelocity_right_collision)
{
    int obj[] = {
        90, 32, 32,
        0, 836, 32, 836, 64, 836, 96, 836, 128, 836, 160, 836, 192, 836, 224, 836, 256, 836, 288, 836,
        320, 836, 352, 836, 384, 836, 416, 836, 448, 836, 480, 836, 512, 836, 544, 836, 576, 836, 608, 836,
        640, 836, 672, 836, 704, 836, 736, 836, 768, 836, 800, 836, 832, 836, 864, 836, 896, 836, 928, 836,
        960, 836, 992, 836, 1024, 836, 1056, 836, 1088, 836, 1120, 836, 1152, 836, 1184, 836, 1216, 836, 1248, 836,
        1280, 836, 1312, 836, 1344, 836, 1376, 836, 1408, 836, 1440, 836, 1472, 836, 1504, 836, 1536, 836, 1568, 836,
        288, 804, 288, 772, 288, 740, 288, 708, 288, 676, 288, 644, 288, 612, 288, 580, 288, 548, 288, 516,
        288, 484, 288, 452, 288, 420, 288, 388, 288, 356, 288, 324, 288, 292, 288, 260, 288, 228, 288, 196,
        1088, 804, 1088, 772, 1088, 740, 1088, 708, 1088, 676, 1088, 644, 1088, 612, 1088, 580, 1088, 548, 1088, 516,
        1088, 484, 1088, 452, 1088, 420, 1088, 388, 1088, 356, 1088, 324, 1088, 292, 1088, 260, 1088, 228, 1088, 196
    };
    
    vector<int> objects (obj, obj + sizeof(obj) / sizeof(int));  
        
    int col[] = {
        321, 718, 0, 0
    };

    vector<int> collis (col, col + sizeof(col) / sizeof(int));
        
    EXPECT_EQ(objectsCollision(98, 118, 316, 718, -5, 0, objects), collis);
}

TEST(ObjectsCollision_positive, zero_yVelocity_left_collision)
{
    int obj[] = {
        90, 32, 32,
        0, 836, 32, 836, 64, 836, 96, 836, 128, 836, 160, 836, 192, 836, 224, 836, 256, 836, 288, 836,
        320, 836, 352, 836, 384, 836, 416, 836, 448, 836, 480, 836, 512, 836, 544, 836, 576, 836, 608, 836,
        640, 836, 672, 836, 704, 836, 736, 836, 768, 836, 800, 836, 832, 836, 864, 836, 896, 836, 928, 836,
        960, 836, 992, 836, 1024, 836, 1056, 836, 1088, 836, 1120, 836, 1152, 836, 1184, 836, 1216, 836, 1248, 836,
        1280, 836, 1312, 836, 1344, 836, 1376, 836, 1408, 836, 1440, 836, 1472, 836, 1504, 836, 1536, 836, 1568, 836,
        288, 804, 288, 772, 288, 740, 288, 708, 288, 676, 288, 644, 288, 612, 288, 580, 288, 548, 288, 516,
        288, 484, 288, 452, 288, 420, 288, 388, 288, 356, 288, 324, 288, 292, 288, 260, 288, 228, 288, 196,
        1088, 804, 1088, 772, 1088, 740, 1088, 708, 1088, 676, 1088, 644, 1088, 612, 1088, 580, 1088, 548, 1088, 516,
        1088, 484, 1088, 452, 1088, 420, 1088, 388, 1088, 356, 1088, 324, 1088, 292, 1088, 260, 1088, 228, 1088, 196
    };
    
    vector<int> objects (obj, obj + sizeof(obj) / sizeof(int));   

    int col[] = {
        989, 718, 0, 0
    };
        
    vector<int> collis (col, col + sizeof(col) / sizeof(int));  

    EXPECT_EQ(objectsCollision(98, 118, 994, 718, 5, 0, objects), collis);
}

TEST(ObjectsCollision_positive, not_zero_yVelocity_right_collision)
{
    int obj[] = {
        90, 32, 32,
        0, 836, 32, 836, 64, 836, 96, 836, 128, 836, 160, 836, 192, 836, 224, 836, 256, 836, 288, 836,
        320, 836, 352, 836, 384, 836, 416, 836, 448, 836, 480, 836, 512, 836, 544, 836, 576, 836, 608, 836,
        640, 836, 672, 836, 704, 836, 736, 836, 768, 836, 800, 836, 832, 836, 864, 836, 896, 836, 928, 836,
        960, 836, 992, 836, 1024, 836, 1056, 836, 1088, 836, 1120, 836, 1152, 836, 1184, 836, 1216, 836, 1248, 836,
        1280, 836, 1312, 836, 1344, 836, 1376, 836, 1408, 836, 1440, 836, 1472, 836, 1504, 836, 1536, 836, 1568, 836,
        288, 804, 288, 772, 288, 740, 288, 708, 288, 676, 288, 644, 288, 612, 288, 580, 288, 548, 288, 516,
        288, 484, 288, 452, 288, 420, 288, 388, 288, 356, 288, 324, 288, 292, 288, 260, 288, 228, 288, 196,
        1088, 804, 1088, 772, 1088, 740, 1088, 708, 1088, 676, 1088, 644, 1088, 612, 1088, 580, 1088, 548, 1088, 516,
        1088, 484, 1088, 452, 1088, 420, 1088, 388, 1088, 356, 1088, 324, 1088, 292, 1088, 260, 1088, 228, 1088, 196
    };
    
    vector<int> objects (obj, obj + sizeof(obj) / sizeof(int));

    int col[] = {
        321, 718, 0, 1
    };
        
    vector<int> collis (col, col + sizeof(col) / sizeof(int));   

    EXPECT_EQ(objectsCollision(98, 118, 316, 719, -5, 1, objects), collis);
}

TEST(ObjectsCollision_positive, not_zero_yVelocity_left_collision)
{
    int obj[] = {
        90, 32, 32,
        0, 836, 32, 836, 64, 836, 96, 836, 128, 836, 160, 836, 192, 836, 224, 836, 256, 836, 288, 836,
        320, 836, 352, 836, 384, 836, 416, 836, 448, 836, 480, 836, 512, 836, 544, 836, 576, 836, 608, 836,
        640, 836, 672, 836, 704, 836, 736, 836, 768, 836, 800, 836, 832, 836, 864, 836, 896, 836, 928, 836,
        960, 836, 992, 836, 1024, 836, 1056, 836, 1088, 836, 1120, 836, 1152, 836, 1184, 836, 1216, 836, 1248, 836,
        1280, 836, 1312, 836, 1344, 836, 1376, 836, 1408, 836, 1440, 836, 1472, 836, 1504, 836, 1536, 836, 1568, 836,
        288, 804, 288, 772, 288, 740, 288, 708, 288, 676, 288, 644, 288, 612, 288, 580, 288, 548, 288, 516,
        288, 484, 288, 452, 288, 420, 288, 388, 288, 356, 288, 324, 288, 292, 288, 260, 288, 228, 288, 196,
        1088, 804, 1088, 772, 1088, 740, 1088, 708, 1088, 676, 1088, 644, 1088, 612, 1088, 580, 1088, 548, 1088, 516,
        1088, 484, 1088, 452, 1088, 420, 1088, 388, 1088, 356, 1088, 324, 1088, 292, 1088, 260, 1088, 228, 1088, 196
    };
    
    vector<int> objects (obj, obj + sizeof(obj) / sizeof(int));
        
    int col[] = {
        989, 718, 0, 0
    };

    vector<int> collis (col, col + sizeof(col) / sizeof(int)); 

    EXPECT_EQ(objectsCollision(98, 118, 994, 719, 5, 1, objects), collis);
}

TEST(ObjectsCollision_positive, up_collision)
{
    int obj[] = {
        90, 32, 32,
        0, 836, 32, 836, 64, 836, 96, 836, 128, 836, 160, 836, 192, 836, 224, 836, 256, 836, 288, 836,
        320, 836, 352, 836, 384, 836, 416, 836, 448, 836, 480, 836, 512, 836, 544, 836, 576, 836, 608, 836,
        640, 836, 672, 836, 704, 836, 736, 836, 768, 836, 800, 836, 832, 836, 864, 836, 896, 836, 928, 836,
        960, 836, 992, 836, 1024, 836, 1056, 836, 1088, 836, 1120, 836, 1152, 836, 1184, 836, 1216, 836, 1248, 836,
        1280, 836, 1312, 836, 1344, 836, 1376, 836, 1408, 836, 1440, 836, 1472, 836, 1504, 836, 1536, 836, 1568, 836,
        288, 804, 288, 772, 288, 740, 288, 708, 288, 676, 288, 644, 288, 612, 288, 580, 288, 548, 288, 516,
        288, 484, 288, 452, 288, 420, 288, 388, 288, 356, 288, 324, 288, 292, 288, 260, 288, 228, 288, 196,
        1088, 804, 1088, 772, 1088, 740, 1088, 708, 1088, 676, 1088, 644, 1088, 612, 1088, 580, 1088, 548, 1088, 516,
        1088, 484, 1088, 452, 1088, 420, 1088, 388, 1088, 356, 1088, 324, 1088, 292, 1088, 260, 1088, 228, 1088, 196
    };
    
    vector<int> objects (obj, obj + sizeof(obj) / sizeof(int));   
        
    int col[] = {
        666, 718, 0, 1
    };

    vector<int> collis (col, col + sizeof(col) / sizeof(int));  

    EXPECT_EQ(objectsCollision(98, 118, 666, 719, 0, 1, objects), collis);
}

TEST(ObjectsCollision_positive, down_collision)
{
    int obj[] = {
        100, 32, 32,
        0, 600, 32, 600, 64, 600, 96, 600, 128, 600, 160, 600, 192, 600, 224, 600, 256, 600, 288, 600,
        320, 600, 352, 600, 384, 600, 416, 600, 448, 600, 480, 600, 512, 600, 544, 600, 576, 600, 608, 600,
        640, 600, 672, 600, 704, 600, 736, 600, 768, 600, 800, 600, 832, 600, 864, 600, 896, 600, 928, 600,
        960, 600, 992, 600, 1024, 600, 1056, 600, 1088, 600, 1120, 600, 1152, 600, 1184, 600, 1216, 600, 1248, 600,
        1280, 600, 1312, 600, 1344, 600, 1376, 600, 1408, 600, 1440, 600, 1472, 600, 1504, 600, 1536, 600, 1568, 600,
        0, 836, 32, 836, 64, 836, 96, 836, 128, 836, 160, 836, 192, 836, 224, 836, 256, 836, 288, 836,
        320, 836, 352, 836, 384, 836, 416, 836, 448, 836, 480, 836, 512, 836, 544, 836, 576, 836, 608, 836,
        640, 836, 672, 836, 704, 836, 736, 836, 768, 836, 800, 836, 832, 836, 864, 836, 896, 836, 928, 836,
        960, 836, 992, 836, 1024, 836, 1056, 836, 1088, 836, 1120, 836, 1152, 836, 1184, 836, 1216, 836, 1248, 836,
        1280, 836, 1312, 836, 1344, 836, 1376, 836, 1408, 836, 1440, 836, 1472, 836, 1504, 836, 1536, 836, 1568, 836
    };
    
    vector<int> objects (obj, obj + sizeof(obj) / sizeof(int));  
        
    int col[] = {
        791, 632, 0, 2
    };

    vector<int> collis (col, col + sizeof(col) / sizeof(int));

    EXPECT_EQ(objectsCollision(98, 118, 791, 631, 0, -28, objects), collis);
}

TEST(ObjectsCollision_positive, inside_collision)
{
    int obj[] = {
        70, 32, 32,
        0, 836, 32, 836, 64, 836, 96, 836, 128, 836, 160, 836, 192, 836, 224, 836, 256, 836, 288, 836,
        320, 836, 352, 836, 384, 836, 416, 836, 448, 836, 480, 836, 512, 836, 544, 836, 576, 836, 608, 836,
        640, 836, 672, 836, 704, 836, 736, 836, 768, 836, 800, 836, 832, 836, 864, 836, 896, 836, 928, 836,
        960, 836, 992, 836, 1024, 836, 1056, 836, 1088, 836, 1120, 836, 1152, 836, 1184, 836, 1216, 836, 1248, 836,
        1280, 836, 1312, 836, 1344, 836, 1376, 836, 1408, 836, 1440, 836, 1472, 836, 1504, 836, 1536, 836, 1568, 836,
        1260, 580, 1260, 548, 1260, 516, 1260, 484, 1260, 452, 1260, 420, 1260, 388, 1260, 356, 1260, 324, 1260, 292,
        1100, 600, 1132, 600, 1164, 600, 1196, 600, 1228, 600, 1260, 600, 1292, 600, 1324, 600, 1356, 600, 1388, 600
    };
    
    vector<int> objects (obj, obj + sizeof(obj) / sizeof(int));  
        
    int col[] = {
        1156, 482, 0, 1
    };

    vector<int> collis (col, col + sizeof(col) / sizeof(int));  

    EXPECT_EQ(objectsCollision(98, 118, 1166, 483, 5, 1, objects), collis);
}

TEST(ObjectsCollision_negative, sizes_not_more_0)
{
    int obj[] = {
        70, -32, -32,
        0, 836, 32, 836, 64, 836, 96, 836, 128, 836, 160, 836, 192, 836, 224, 836, 256, 836, 288, 836,
        320, 836, 352, 836, 384, 836, 416, 836, 448, 836, 480, 836, 512, 836, 544, 836, 576, 836, 608, 836,
        640, 836, 672, 836, 704, 836, 736, 836, 768, 836, 800, 836, 832, 836, 864, 836, 896, 836, 928, 836,
        960, 836, 992, 836, 1024, 836, 1056, 836, 1088, 836, 1120, 836, 1152, 836, 1184, 836, 1216, 836, 1248, 836,
        1280, 836, 1312, 836, 1344, 836, 1376, 836, 1408, 836, 1440, 836, 1472, 836, 1504, 836, 1536, 836, 1568, 836,
        1260, 580, 1260, 548, 1260, 516, 1260, 484, 1260, 452, 1260, 420, 1260, 388, 1260, 356, 1260, 324, 1260, 292,
        1100, 600, 1132, 600, 1164, 600, 1196, 600, 1228, 600, 1260, 600, 1292, 600, 1324, 600, 1356, 600, 1388, 600
    };
    
    vector<int> objects (obj, obj + sizeof(obj) / sizeof(int));
        
    int col[] = {
        1166, 483, -1, 0
    };

    vector<int> collis (col, col + sizeof(col) / sizeof(int));  

    EXPECT_EQ(objectsCollision(-98, -118, 1166, 483, -5, -1, objects), collis);
}


