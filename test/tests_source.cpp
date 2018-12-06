//
// Created by Jamahl Watson on 31/10/2018.
//

#include "gtest/gtest.h"

TEST(UnitTests, oneIsOne) {
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}