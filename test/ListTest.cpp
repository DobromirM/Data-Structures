#include "ADT/List.h"
#include "gtest/gtest.h"

TEST(ListTest, testSize) {
    List<int> list{5};

    EXPECT_EQ(5, list.size());
}

TEST(ListTest, testCapacity) {
    List<int> list{5};

    EXPECT_EQ(21, list.capacity());
}