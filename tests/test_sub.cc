#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestSub, TestSub1) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.getRows(), 4);
  EXPECT_EQ(matrix1.getCols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.getRows(), 4);
  EXPECT_EQ(matrix2.getCols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.getRows(), 4);
  EXPECT_EQ(matrix2.getCols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 1.5;
  check_matrix(0, 2) = 1.5;
  check_matrix(1, 0) = -4.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = -7.5;
  check_matrix(2, 0) = 1.0;
  check_matrix(2, 1) = 2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 4.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = -3.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSub, TestSub2) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.getRows(), 95);
  EXPECT_EQ(matrix1.getCols(), 99);

  S21Matrix matrix2{95, 99};
  EXPECT_EQ(matrix2.getRows(), 95);
  EXPECT_EQ(matrix2.getCols(), 99);

  test_helper::FillMatrix(matrix1, 2.5);
  test_helper::FillMatrix(matrix2, 3.5);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 - matrix2;

  EXPECT_EQ(result.getRows(), 95);
  EXPECT_EQ(result.getCols(), 99);
  test_helper::CheckMatrix(result, -1.0);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSub, TestSubException1) {
  S21Matrix matrix1{3, 2};
  S21Matrix matrix2{2, 2};

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 -= matrix2);
  EXPECT_ANY_THROW(matrix2 -= matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSub, TestSub3) {
  S21Matrix matrix1{4, 3};
  EXPECT_EQ(matrix1.getRows(), 4);
  EXPECT_EQ(matrix1.getCols(), 3);

  S21Matrix matrix2{4, 3};
  EXPECT_EQ(matrix2.getRows(), 4);
  EXPECT_EQ(matrix2.getCols(), 3);

  S21Matrix check_matrix{4, 3};
  EXPECT_EQ(matrix2.getRows(), 4);
  EXPECT_EQ(matrix2.getCols(), 3);

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = 2.5;
  matrix1(0, 2) = 3.5;
  matrix1(1, 0) = -1.5;
  matrix1(1, 1) = -2.5;
  matrix1(1, 2) = -3.5;
  matrix1(2, 0) = 0.0;
  matrix1(2, 1) = 0.0;
  matrix1(2, 2) = 0.0;
  matrix1(3, 0) = 1.0;
  matrix1(3, 1) = 1.0;
  matrix1(3, 2) = 1.0;

  matrix2(0, 0) = 0.0;
  matrix2(0, 1) = 1.0;
  matrix2(0, 2) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;
  matrix2(1, 2) = 4.0;
  matrix2(2, 0) = -1.0;
  matrix2(2, 1) = -2.0;
  matrix2(2, 2) = 0.0;
  matrix2(3, 0) = -3.0;
  matrix2(3, 1) = 0.0;
  matrix2(3, 2) = 4.0;

  check_matrix(0, 0) = 1.5;
  check_matrix(0, 1) = 1.5;
  check_matrix(0, 2) = 1.5;
  check_matrix(1, 0) = -4.5;
  check_matrix(1, 1) = -2.5;
  check_matrix(1, 2) = -7.5;
  check_matrix(2, 0) = 1.0;
  check_matrix(2, 1) = 2.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 4.0;
  check_matrix(3, 1) = 1.0;
  check_matrix(3, 2) = -3.0;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1;
  result -= matrix2;

  EXPECT_EQ(result.getRows(), 4);
  EXPECT_EQ(result.getCols(), 3);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}