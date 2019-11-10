#include "ADT/List.h"
#include "gtest/gtest.h"

TEST(ListTest, testCreateInitialEmpty) {
    // When
    List<int> list{};

    // Then
    EXPECT_EQ(0, list.size());
    EXPECT_EQ(16, list.capacity());
}

TEST(ListTest, testCreateInitialOne) {
    // When
    List<int> list{1};

    // Then
    EXPECT_EQ(1, list.size());
    EXPECT_EQ(17, list.capacity());
}

TEST(ListTest, testCreateInitialFive) {
    // When
    List<int> list{5};

    // Then
    EXPECT_EQ(5, list.size());
    EXPECT_EQ(21, list.capacity());
}

TEST(ListTest, testListAssignValues) {
    // Given
    List<int> original{5};

    // When
    original[0] = 5;
    original[1] = 10;
    original[2] = 15;
    original[3] = 20;
    original[4] = 25;

    // Then
    EXPECT_EQ(5, original[0]);
    EXPECT_EQ(10, original[1]);
    EXPECT_EQ(15, original[2]);
    EXPECT_EQ(20, original[3]);
    EXPECT_EQ(25, original[4]);
}

TEST(ListTest, testListCopyConstructor) {
    // Given
    List<int> original{5};
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    original[3] = 4;
    original[4] = 5;

    // When
    const List<int> actual{original};
    original[0] = 0;
    original[1] = 0;
    original[2] = 0;
    original[3] = 0;

    // Then
    EXPECT_EQ(1, actual[0]);
    EXPECT_EQ(2, actual[1]);
    EXPECT_EQ(3, actual[2]);
    EXPECT_EQ(4, actual[3]);
    EXPECT_EQ(5, actual[4]);
}

TEST(ListTest, testListCopyConstructorConst) {
    // Given
    List<int> original{5};
    original[0] = 5;
    original[1] = 10;
    original[2] = 15;
    original[3] = 20;
    original[4] = 25;

    // When
    List<int> actual{original};
    original[0] = 0;
    original[1] = 0;
    original[2] = 0;
    original[3] = 0;
    original[4] = 0;

    // Then
    EXPECT_EQ(5, actual[0]);
    EXPECT_EQ(10, actual[1]);
    EXPECT_EQ(15, actual[2]);
    EXPECT_EQ(20, actual[3]);
    EXPECT_EQ(25, actual[4]);
}

TEST(ListTest, testListMoveConstructor) {
    // Given
    List<int> original{5};
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    original[3] = 4;
    original[4] = 5;

    // When
    List<int> actual{std::move(original)};

    // Then
    EXPECT_EQ(1, actual[0]);
    EXPECT_EQ(2, actual[1]);
    EXPECT_EQ(3, actual[2]);
    EXPECT_EQ(4, actual[3]);
    EXPECT_EQ(5, actual[4]);
}

TEST(ListTest, testListCopyAssignment) {
    // Given
    List<int> original{5};
    original[0] = 20;
    original[1] = 21;
    original[2] = 22;
    original[3] = 23;
    original[4] = 24;

    // When
    List<int> actual{};
    actual = original;

    // Then
    EXPECT_EQ(20, actual[0]);
    EXPECT_EQ(21, actual[1]);
    EXPECT_EQ(22, actual[2]);
    EXPECT_EQ(23, actual[3]);
    EXPECT_EQ(24, actual[4]);
}

TEST(ListTest, testListMoveAssignment) {
    // Given
    List<int> original{5};
    original[0] = 30;
    original[1] = 31;
    original[2] = 32;
    original[3] = 33;
    original[4] = 34;

    // When
    List<int> actual{};
    actual = std::move(original);

    // Then
    EXPECT_EQ(30, actual[0]);
    EXPECT_EQ(31, actual[1]);
    EXPECT_EQ(32, actual[2]);
    EXPECT_EQ(33, actual[3]);
    EXPECT_EQ(34, actual[4]);
}

TEST(ListTest, testIsEmptyTrue) {
    // Given
    List<int> original{0};

    //Then
    EXPECT_TRUE(original.isEmpty());
}

TEST(ListTest, testIsEmptyFalse) {
    // Given
    List<int> original{2};

    //Then
    EXPECT_FALSE(original.isEmpty());
}