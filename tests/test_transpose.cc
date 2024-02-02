#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestTranspose, TestTranspose4) {
  S21Matrix matrix1{1, 4};
  EXPECT_EQ(matrix1.getRows(), 1);
  EXPECT_EQ(matrix1.getCols(), 4);

  S21Matrix result_check{4, 1};
  EXPECT_EQ(result_check.getRows(), 4);
  EXPECT_EQ(result_check.getCols(), 1);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(0, 3) = 4;

  result_check(0, 0) = 1;
  result_check(1, 0) = 2;
  result_check(2, 0) = 3;
  result_check(3, 0) = 4;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestTranspose, TestTranspose7) {
  S21Matrix matrix1{3, 2};
  EXPECT_EQ(matrix1.getRows(), 3);
  EXPECT_EQ(matrix1.getCols(), 2);

  S21Matrix result_check{2, 3};
  EXPECT_EQ(result_check.getRows(), 2);
  EXPECT_EQ(result_check.getCols(), 3);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = 6;

  result_check(0, 0) = 1;
  result_check(1, 0) = 2;
  result_check(0, 1) = 3;
  result_check(1, 1) = 4;
  result_check(0, 2) = 5;
  result_check(1, 2) = 6;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}