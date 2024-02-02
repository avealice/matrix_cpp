#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestMulNumber, TestMulNumber1) {
  S21Matrix matrix(95, 99);
  EXPECT_EQ(matrix.getRows(), 95);
  EXPECT_EQ(matrix.getCols(), 99);

  double number = 2.0;

  test_helper::FillMatrix(matrix, 2.5);

  matrix.MulNumber(number);

  test_helper::CheckMatrix(matrix, 2.5 * number);

  matrix.MulNumber(number);

  test_helper::CheckMatrix(matrix, 2.5 * number * number);
}

TEST(TestMulNumber, TestMulNumber2) {
  S21Matrix matrix(4, 3);
  EXPECT_EQ(matrix.getRows(), 4);
  EXPECT_EQ(matrix.getCols(), 3);

  S21Matrix check_matrix = matrix;
  EXPECT_EQ(check_matrix.getRows(), 4);
  EXPECT_EQ(check_matrix.getCols(), 3);

  double number = 1.99;

  matrix(0, 0) = 1.5;
  matrix(0, 1) = 2.5;
  matrix(0, 2) = 3.5;
  matrix(1, 0) = -1.5;
  matrix(1, 1) = -2.5;
  matrix(1, 2) = -3.5;
  matrix(2, 0) = 0.0;
  matrix(2, 1) = 0.0;
  matrix(2, 2) = 0.0;
  matrix(3, 0) = 1.0;
  matrix(3, 1) = 1.0;
  matrix(3, 2) = 1.0;

  check_matrix(0, 0) = 2.985;
  check_matrix(0, 1) = 4.975;
  check_matrix(0, 2) = 6.965;
  check_matrix(1, 0) = -2.985;
  check_matrix(1, 1) = -4.975;
  check_matrix(1, 2) = -6.965;
  check_matrix(2, 0) = 0.0;
  check_matrix(2, 1) = 0.0;
  check_matrix(2, 2) = 0.0;
  check_matrix(3, 0) = 1.99;
  check_matrix(3, 1) = 1.99;
  check_matrix(3, 2) = 1.99;

  matrix.MulNumber(number);

  EXPECT_TRUE(matrix == check_matrix);
}

TEST(TestMulNumber, TestMulNumberOperator1) {
  S21Matrix matrix{99, 99};
  EXPECT_EQ(matrix.getRows(), 99);
  EXPECT_EQ(matrix.getCols(), 99);

  double number = -2.5;

  test_helper::FillMatrix(matrix, 2.5);
  S21Matrix matrix_before = matrix;
  S21Matrix result1 = matrix * number;
  S21Matrix result2 = number * matrix;
  S21Matrix result3 = matrix;
  result3 *= number;

  test_helper::CheckMatrix(result1, 2.5 * number);
  test_helper::CheckMatrix(result2, 2.5 * number);
  test_helper::CheckMatrix(result3, 2.5 * number);
  EXPECT_TRUE(matrix_before == matrix);
}
