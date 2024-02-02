#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestEq, TestEqException) {
  S21Matrix matrix1(1, 1);
  S21Matrix matrix2(1, 1);

  matrix1(0, 0) = -1;
  matrix2(0, 0) = 2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq1) {
  S21Matrix matrix1(2, 2);
  EXPECT_EQ(matrix1.getCols(), 2);
  EXPECT_EQ(matrix1.getRows(), 2);

  S21Matrix matrix2(2, 2);
  EXPECT_EQ(matrix2.getCols(), 2);
  EXPECT_EQ(matrix2.getRows(), 2);

  test_helper::CheckMatrix(matrix1, 0.0);
  test_helper::CheckMatrix(matrix2, 0.0);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  test_helper::CheckMatrix(matrix1, 0.0);
  test_helper::CheckMatrix(matrix2, 0.0);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq2) {
  S21Matrix matrix1(3, 3);
  EXPECT_EQ(matrix1.getCols(), 3);
  EXPECT_EQ(matrix1.getRows(), 3);

  S21Matrix matrix2(2, 2);
  EXPECT_EQ(matrix2.getCols(), 2);
  EXPECT_EQ(matrix2.getRows(), 2);

  test_helper::CheckMatrix(matrix1, 0.0);
  test_helper::CheckMatrix(matrix2, 0.0);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result1);
  EXPECT_FALSE(matrix1 == matrix2);

  test_helper::CheckMatrix(matrix1, 0.0);
  test_helper::CheckMatrix(matrix2, 0.0);

  test_helper::FillMatrix(matrix1, 2.0);
  test_helper::FillMatrix(matrix2, 2.0);

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);

  test_helper::CheckMatrix(matrix1, 2.0);
  test_helper::CheckMatrix(matrix2, 2.0);
}

TEST(TestEq, TestEq3) {
  S21Matrix matrix1(2, 2);
  EXPECT_EQ(matrix1.getCols(), 2);
  EXPECT_EQ(matrix1.getRows(), 2);

  S21Matrix matrix2(2, 2);
  EXPECT_EQ(matrix2.getCols(), 2);
  EXPECT_EQ(matrix2.getRows(), 2);

  test_helper::CheckMatrix(matrix1, 0.0);
  test_helper::CheckMatrix(matrix2, 0.0);

  matrix2(0, 0) = 0.0000001;

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  test_helper::CheckMatrix(matrix1, 0.0);
  test_helper::CheckMatrix(matrix2, 0.0);

  matrix1(0, 0) = 0.0000001;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);

  test_helper::CheckMatrix(matrix1, 0.0);
  test_helper::CheckMatrix(matrix2, 0.0);
}