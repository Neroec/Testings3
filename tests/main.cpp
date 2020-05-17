#include <gtest/gtest.h>

#include "XCollision.h"
#include "YCollision.h"
#include "ObjectsCollision.h"
#include "CoinsCollision.h"
#include "MarioStatus.h"
#include "ObjectsStorage.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
