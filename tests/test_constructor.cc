#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestConstructor, TestConstructor1) {
  S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.getRows(), 0);
  EXPECT_EQ(matrix_check.getCols(), 0);
}

TEST(TestConstructor, TestConstructorParams) {
  S21Matrix matrix_check(5, 4);
  EXPECT_EQ(matrix_check.getRows(), 5);
  EXPECT_EQ(matrix_check.getCols(), 4);
  test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorParams1) {
  S21Matrix matrix_check(999, 1999);
  EXPECT_EQ(matrix_check.getRows(), 999);
  EXPECT_EQ(matrix_check.getCols(), 1999);
  test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorCopy) {
  S21Matrix matrix_check = S21Matrix(2, 2);
  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;
  S21Matrix matrix_copy = matrix_check;
  EXPECT_EQ(matrix_check.getCols(), 2);
  EXPECT_EQ(matrix_check.getRows(), 2);
  EXPECT_EQ(matrix_copy.getCols(), 2);
  EXPECT_EQ(matrix_copy.getRows(), 2);
  test_helper::CheckMatrix(matrix_check, 4.0);
  test_helper::CheckMatrix(matrix_copy, 4.0);
}

TEST(TestConstructor, TestConstructorMove) {
  S21Matrix matrix_check = test_helper::TestMoveConstructor(S21Matrix{5, 5});
  EXPECT_EQ(matrix_check.getCols(), 5);
  EXPECT_EQ(matrix_check.getRows(), 5);
  test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestConstructor, TestConstructorCopy1) {
  S21Matrix matrix_test(5, 5);
  S21Matrix matrix_check(2, 2);
  test_helper::FillMatrix(matrix_test, 2.0);
  test_helper::FillMatrix(matrix_check, 5.0);
  matrix_check = matrix_test;
  EXPECT_EQ(matrix_check.getCols(), 5);
  EXPECT_EQ(matrix_check.getRows(), 5);
  EXPECT_EQ(matrix_test.getCols(), 5);
  EXPECT_EQ(matrix_test.getRows(), 5);
  test_helper::CheckMatrix(matrix_test, 2.0);
  test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestConstructor, TestConstructorMove2) {
  S21Matrix matrix_test(5, 5);
  S21Matrix matrix_check(2, 2);
  test_helper::FillMatrix(matrix_test, 2.0);
  test_helper::FillMatrix(matrix_check, 5.0);
  matrix_check = std::move(matrix_test);
  EXPECT_EQ(matrix_check.getCols(), 5);
  EXPECT_EQ(matrix_check.getRows(), 5);
  EXPECT_EQ(matrix_test.getCols(), 0);
  EXPECT_EQ(matrix_test.getRows(), 0);
  test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestConstructor, TestConstructorException) {
  EXPECT_ANY_THROW(S21Matrix(-1, 99));
}

TEST(TestConstructor, TestConstructorException1) {
  EXPECT_ANY_THROW(S21Matrix(99, -1));
}

TEST(TestConstructor, TestConstructorException2) {
  EXPECT_ANY_THROW(S21Matrix(-99, -99));
}
