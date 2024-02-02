#include <gtest/gtest.h>
#include "test_helper.h"

// TEST(TestCalcComplements, TestCalcComplementsOne1) {
//   S21Matrix test_matrix(1, 1);

//   EXPECT_EQ(test_matrix.getRows(), 1);
//   EXPECT_EQ(test_matrix.getCols(), 1);

//   S21Matrix matrix_before = test_matrix;
//   S21Matrix result;

//   EXPECT_NO_THROW(result = test_matrix.CalcComplements());
//   EXPECT_TRUE(test_matrix == matrix_before);

//   EXPECT_EQ(result.getRows(), 1);
//   EXPECT_EQ(result.getCols(), 1);
//   EXPECT_EQ(result(0, 0), 1.0);
// }


TEST(TestCalcComplements, TestCalcComplementsException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.CalcComplements());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements1) {
  S21Matrix matrix1(3, 3);
  EXPECT_EQ(matrix1.getRows(), 3);
  EXPECT_EQ(matrix1.getCols(), 3);

  S21Matrix result_check{3, 3};
  EXPECT_EQ(result_check.getRows(), 3);
  EXPECT_EQ(result_check.getCols(), 3);

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(2, 0) = 3;
  matrix1(0, 1) = 4;
  matrix1(1, 1) = 5;
  matrix1(2, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 2) = 8;
  matrix1(2, 2) = 9;

  result_check(0, 0) = -3;
  result_check(1, 0) = 6;
  result_check(2, 0) = -3;
  result_check(0, 1) = 6;
  result_check(1, 1) = -12;
  result_check(2, 1) = 6;
  result_check(0, 2) = -3;
  result_check(1, 2) = 6;
  result_check(2, 2) = -3;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}