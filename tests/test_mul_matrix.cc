#include <gtest/gtest.h>
#include "test_helper.h"


TEST(TestMulMatrix, TestMulMatrix1) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.getRows(), 99);
  EXPECT_EQ(matrix1.getCols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.getRows(), 99);
  EXPECT_EQ(matrix2.getCols(), 99);

  S21Matrix check_matrix{99, 99};
  EXPECT_EQ(check_matrix.getRows(), 99);
  EXPECT_EQ(check_matrix.getCols(), 99);

  test_helper::FillMatrix(matrix1, 1.0);
  test_helper::FillMatrix(matrix2, 0.0);
  test_helper::FillMatrix(check_matrix, 0.0);

  S21Matrix matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.getRows(), 99);
  EXPECT_EQ(matrix1.getCols(), 99);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.getRows(), 2);
  EXPECT_EQ(matrix1.getCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.getRows(), 2);
  EXPECT_EQ(matrix2.getCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(check_matrix.getRows(), 2);
  EXPECT_EQ(check_matrix.getCols(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  check_matrix(0, 0) = 10;
  check_matrix(0, 1) = 13;
  check_matrix(1, 0) = 22;
  check_matrix(1, 1) = 29;

  S21Matrix matrix2_before = matrix2;
  matrix1.MulMatrix(matrix2);

  EXPECT_EQ(matrix1.getRows(), 2);
  EXPECT_EQ(matrix1.getCols(), 2);

  ASSERT_TRUE(matrix1 == check_matrix);
  ASSERT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixException1) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 2);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
  EXPECT_ANY_THROW(matrix2.MulMatrix(matrix1));
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrixException2) {
  S21Matrix matrix1(3, 2);
  S21Matrix matrix2(3, 2);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 * matrix2);
  EXPECT_ANY_THROW(matrix2 * matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestMulMatrix, TestMulMatrix3) {
  S21Matrix matrix1{99, 99};
  EXPECT_EQ(matrix1.getRows(), 99);
  EXPECT_EQ(matrix1.getCols(), 99);

  S21Matrix matrix2{99, 99};
  EXPECT_EQ(matrix2.getRows(), 99);
  EXPECT_EQ(matrix2.getCols(), 99);

  S21Matrix check_matrix{99, 99};
  EXPECT_EQ(check_matrix.getRows(), 99);
  EXPECT_EQ(check_matrix.getCols(), 99);

  test_helper::FillMatrix(matrix1, 1.0);
  test_helper::FillMatrix(matrix2, 0.0);
  test_helper::FillMatrix(check_matrix, 0.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  S21Matrix result1 = matrix1 * matrix2;
  S21Matrix result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}

TEST(TestMulMatrix, TestMulMatrixOperator1) {
  S21Matrix matrix1{95, 98};
  EXPECT_EQ(matrix1.getRows(), 95);
  EXPECT_EQ(matrix1.getCols(), 98);

  S21Matrix matrix2{98, 99};
  EXPECT_EQ(matrix2.getRows(), 98);
  EXPECT_EQ(matrix2.getCols(), 99);

  S21Matrix check_matrix{95, 99};
  EXPECT_EQ(check_matrix.getRows(), 95);
  EXPECT_EQ(check_matrix.getCols(), 99);

  test_helper::FillMatrix(matrix1, 1.0);
  test_helper::FillMatrix(matrix2, 1.0);
  test_helper::FillMatrix(check_matrix, 98.0);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  S21Matrix result1 = matrix1 * matrix2;
  S21Matrix result2 = matrix1;
  result2 *= matrix2;

  ASSERT_TRUE(result1 == check_matrix);
  ASSERT_TRUE(result2 == check_matrix);
  ASSERT_TRUE(matrix1_before == matrix1);
  ASSERT_TRUE(matrix2_before == matrix2);
}
