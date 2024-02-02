#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestGetMinor, TestGetMinor1) {
    S21Matrix matrix1(3, 3);
    EXPECT_EQ(matrix1.getRows(), 3);
    EXPECT_EQ(matrix1.getCols(), 3);

    matrix1(0, 0) = 2.5;
    matrix1(0, 1) = 3;
    matrix1(0, 2) = 7;
    matrix1(1, 0) = 0.7;
    matrix1(1, 1) = 5.1;
    matrix1(1, 2) = 2;
    matrix1(2, 0) = 0;
    matrix1(2, 1) = 1;
    matrix1(2, 2) = 4.8;

    S21Matrix matrix2(2, 2);
    EXPECT_EQ(matrix2.getRows(), 2);
    EXPECT_EQ(matrix2.getCols(), 2);
    
    matrix2(0, 0) = 5.1;
    matrix2(0, 1) = 2;
    matrix2(1, 0) = 1;
    matrix2(1, 1) = 4.8;

    S21Matrix check_matrix = matrix1.MinorMatrix(0, 0);
    EXPECT_TRUE(check_matrix == matrix2);
}