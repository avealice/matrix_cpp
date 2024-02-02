#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestSum, TestSum1) {
  S21Matrix matrix1{95, 99};
  EXPECT_EQ(matrix1.getRows(), 95);
  EXPECT_EQ(matrix1.getCols(), 99);

  S21Matrix matrix2{95, 99};
  EXPECT_EQ(matrix2.getRows(), 95);
  EXPECT_EQ(matrix2.getCols(), 99);

  test_helper::FillMatrix(matrix1, 2.5);
  test_helper::FillMatrix(matrix2, 3.5);

  matrix1.SumMatrix(matrix2);

  test_helper::CheckMatrix(matrix1, 2.5 + 3.5);

  matrix2.SumMatrix(matrix1);

  test_helper::CheckMatrix(matrix2, 3.5 + 2.5 + 3.5);
}

TEST(TestSum, TestSum2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.getRows(), 2);
  EXPECT_EQ(matrix1.getCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.getRows(), 2);
  EXPECT_EQ(matrix2.getCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.getRows(), 2);
  EXPECT_EQ(matrix2.getCols(), 2);

  matrix1(0, 0) = 1264747.4758;
  matrix1(0, 1) = -74763;
  matrix1(1, 0) = 6447.00003;
  matrix1(1, 1) = 1233.432;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -74763;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 15832548.2528;
  check_matrix(0, 1) = -149526;
  check_matrix(1, 0) = 6450.00003;
  check_matrix(1, 1) = 1233.432;

  matrix1.SumMatrix(matrix2);

  EXPECT_TRUE(matrix1 == check_matrix);
}

TEST(TestSum, TestSum3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.getRows(), 2);
  EXPECT_EQ(matrix1.getCols(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.getRows(), 2);
  EXPECT_EQ(matrix2.getCols(), 2);

  S21Matrix check_matrix{2, 2};
  EXPECT_EQ(matrix2.getRows(), 2);
  EXPECT_EQ(matrix2.getCols(), 2);

  matrix1(0, 0) = 1264747.4758;
  matrix1(0, 1) = -74763;
  matrix1(1, 0) = 6447.00003;
  matrix1(1, 1) = 1233.432;

  matrix2(0, 0) = 14567800.777;
  matrix2(0, 1) = -74763;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 0.0;

  check_matrix(0, 0) = 15832548.2528;
  check_matrix(0, 1) = -149526;
  check_matrix(1, 0) = 6450.00003;
  check_matrix(1, 1) = 1233.432;

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;
  S21Matrix result = matrix1 + matrix2;

  EXPECT_EQ(result.getRows(), 2);
  EXPECT_EQ(result.getCols(), 2);

  EXPECT_TRUE(result == check_matrix);
  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}

TEST(TestSum, TestSumException) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 3);

  S21Matrix matrix1_before = matrix1;
  S21Matrix matrix2_before = matrix2;

  EXPECT_ANY_THROW(matrix1 + matrix2);
  EXPECT_ANY_THROW(matrix2 + matrix1);
  EXPECT_TRUE(matrix1 == matrix1_before);
  EXPECT_TRUE(matrix2 == matrix2_before);
}

TEST(TestSum, TestSumOperation5) {
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
  S21Matrix result{95, 99};

  result += matrix1;

  EXPECT_EQ(result.getRows(), 95);
  EXPECT_EQ(result.getCols(), 99);
  test_helper::CheckMatrix(result, 2.5);

  result += matrix2;

  EXPECT_EQ(result.getRows(), 95);
  EXPECT_EQ(result.getCols(), 99);
  test_helper::CheckMatrix(result, 2.5 + 3.5);

  EXPECT_TRUE(matrix1_before == matrix1);
  EXPECT_TRUE(matrix2_before == matrix2);
}
