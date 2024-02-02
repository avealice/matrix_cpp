#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestOperatorBrackets, TestBracketsException1) {
  S21Matrix matrix_check(99, 99);
  EXPECT_ANY_THROW(matrix_check(100, 99));
  test_helper::CheckMatrix(matrix_check, 0.0);
}

TEST(TestOperatorBrackets, TestOperatorBracketsException2) {
  S21Matrix matrix_check(5, 5);
  test_helper::FillMatrix(matrix_check, 2.0);
  EXPECT_NO_THROW(matrix_check(4, 4));
  test_helper::CheckMatrix(matrix_check, 2.0);
}

TEST(TestOperatorBrackets, TestOperatorBrackets1) {
  S21Matrix matrix_check(3, 3);
  EXPECT_EQ(matrix_check.getRows(), 3);
  EXPECT_EQ(matrix_check.getCols(), 3);

  ASSERT_NEAR(matrix_check(0, 0), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(0, 1), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(1, 0), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(1, 1), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, test_helper::eps);

  matrix_check(0, 0) = 1.0;
  matrix_check(0, 1) = 2.0;
  matrix_check(1, 0) = 3.0;
  matrix_check(1, 1) = 4.0;

  ASSERT_NEAR(matrix_check(0, 0), 1.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(0, 1), 2.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(0, 2), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(1, 0), 3.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(1, 1), 4.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(1, 2), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(2, 0), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(2, 1), 0.0, test_helper::eps);
  ASSERT_NEAR(matrix_check(2, 2), 0.0, test_helper::eps);
}