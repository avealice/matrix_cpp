#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestSetter, TestSetRows1){
  S21Matrix matrix{1, 1};
  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 1);

  test_helper::FillMatrix(matrix, 5.5);
  matrix.setRows(2);

  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 1);

  EXPECT_NEAR(matrix(0, 0), 5.5, test_helper::eps);
  EXPECT_NEAR(matrix(1, 0), 0.0, test_helper::eps);
}

TEST(TestSetter, TestSetRows2) {
  S21Matrix matrix{2, 2};
  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  matrix.setRows(3);

  EXPECT_EQ(matrix.getRows(), 3);
  EXPECT_EQ(matrix.getCols(), 2);

  EXPECT_NEAR(matrix(0, 0), 1, test_helper::eps);
  EXPECT_NEAR(matrix(0, 1), 2, test_helper::eps);
  EXPECT_NEAR(matrix(1, 0), 3, test_helper::eps);
  EXPECT_NEAR(matrix(1, 1), 4, test_helper::eps);
  EXPECT_NEAR(matrix(2, 0), 0, test_helper::eps);
  EXPECT_NEAR(matrix(2, 1), 0, test_helper::eps);
}

TEST(TestSetter, TestSetRows3){
  S21Matrix matrix{2, 2};
  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);

  test_helper::FillMatrix(matrix, 5.5);
  matrix.setRows(1);

  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 2);

  EXPECT_NEAR(matrix(0, 0), 5.5, test_helper::eps);
  EXPECT_NEAR(matrix(0, 1), 5.5, test_helper::eps);
}

TEST(TestSetter, TestSetRows4) {
  S21Matrix matrix{1, 1};
  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 1);

  test_helper::FillMatrix(matrix, 5.5);
  matrix.setRows(1);

  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 1);

  EXPECT_NEAR(matrix(0, 0), 5.5, test_helper::eps);
}

TEST(TestSetter, TestSetCols1) {
  S21Matrix matrix{1, 1};
  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 1);

  test_helper::FillMatrix(matrix, 5.5);
  matrix.setCols(2);

  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 2);

  EXPECT_NEAR(matrix(0, 0), 5.5, test_helper::eps);
  EXPECT_NEAR(matrix(0, 1), 0.0, test_helper::eps);
}

TEST(TestSetter, TestSetCols2) {
  S21Matrix matrix{1, 1};
  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 1);

  test_helper::FillMatrix(matrix, 5.5);
  matrix.setCols(1);

  EXPECT_EQ(matrix.getRows(), 1);
  EXPECT_EQ(matrix.getCols(), 1);

  EXPECT_NEAR(matrix(0, 0), 5.5, test_helper::eps);
}

TEST(TestSetter, TestSetCols3) {
  S21Matrix matrix{2, 2};
  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 2);

  test_helper::FillMatrix(matrix, 5.5);
  matrix.setCols(1);

  EXPECT_EQ(matrix.getRows(), 2);
  EXPECT_EQ(matrix.getCols(), 1);

  EXPECT_NEAR(matrix(0, 0), 5.5, test_helper::eps);
  EXPECT_NEAR(matrix(1, 0), 5.5, test_helper::eps);
}

TEST(TestSetter, TestSetterException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.setCols(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestSetter, TestSetterException2) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.setRows(-1));
  EXPECT_TRUE(test_matrix == matrix_before);
}