#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestInverse, TestInverseException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(TestInverse, TestInverseMatrix1) {
  S21Matrix matrix1(3, 3);
  EXPECT_EQ(matrix1.getRows(), 3);
  EXPECT_EQ(matrix1.getCols(), 3);

  matrix1(0, 0) = -5;
  matrix1(0, 1) = -5;
  matrix1(0, 2) = -5;
  matrix1(1, 0) = -5;
  matrix1(1, 1) = -5;
  matrix1(1, 2) = -5;
  matrix1(2, 0) = -5;
  matrix1(2, 1) = -5;
  matrix1(2, 2) = -5;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverseMatrix2) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.getRows(), 5);
  EXPECT_EQ(matrix1.getCols(), 5);

  S21Matrix check_inverse_matrix{5, 5};
  EXPECT_EQ(check_inverse_matrix.getRows(), 5);
  EXPECT_EQ(check_inverse_matrix.getCols(), 5);

  matrix1(0, 0) = 54.5;
  matrix1(0, 1) = 255.5;
  matrix1(0, 2) = 24.5;
  matrix1(0, 3) = 23.5;
  matrix1(0, 4) = 0.0;
  matrix1(1, 0) = 523.3;
  matrix1(1, 1) = 534.2;
  matrix1(1, 2) = 342.4;
  matrix1(1, 3) = 0.0;
  matrix1(1, 4) = 532.3;
  matrix1(2, 0) = 543.2;
  matrix1(2, 1) = 34.3;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 241.3;
  matrix1(2, 4) = 3423.4;
  matrix1(3, 0) = 3625.2;
  matrix1(3, 1) = 0.0;
  matrix1(3, 2) = 3244.0;
  matrix1(3, 3) = 24.4;
  matrix1(3, 4) = 4365.2;
  matrix1(4, 0) = 0.0;
  matrix1(4, 1) = 231.2;
  matrix1(4, 2) = 2314.2;
  matrix1(4, 3) = 1234.1;
  matrix1(4, 4) = 213.2;

  check_inverse_matrix(0, 0) = 8441832269136.3 / 1.2952183794233E+14;
  check_inverse_matrix(0, 1) = -3963589030994.7 / 1.2952183794233E+14;
  check_inverse_matrix(0, 2) = 17086706405.892 / 1.2952183794233E+14;
  check_inverse_matrix(0, 3) = 478403017840.19 / 1.2952183794233E+14;
  check_inverse_matrix(0, 4) = -173550858290.05 / 1.2952183794233E+14;
  check_inverse_matrix(1, 0) = -1860988589140.3 / 1.2952183794233E+14;
  check_inverse_matrix(1, 1) = 1115918880674.1 / 1.2952183794233E+14;
  check_inverse_matrix(1, 2) = -7728325041.456 / 1.2952183794233E+14;
  check_inverse_matrix(1, 3) = -131948153477.35 / 1.2952183794233E+14;
  check_inverse_matrix(1, 4) = 39557257614.576 / 1.2952183794233E+14;
  check_inverse_matrix(2, 0) = -6523983407620.5 / 1.2952183794233E+14;
  check_inverse_matrix(2, 1) = 3062517351997 / 1.2952183794233E+14;
  check_inverse_matrix(2, 2) = -57361768020.684 / 1.2952183794233E+14;
  check_inverse_matrix(2, 3) = -335401997736.92 / 1.2952183794233E+14;
  check_inverse_matrix(2, 4) = 142078286562.88 / 1.2952183794233E+14;
  check_inverse_matrix(3, 0) = 12968602437721 / 1.2952183794233E+14;
  check_inverse_matrix(3, 1) = -6133333912636.1 / 1.2952183794233E+14;
  check_inverse_matrix(3, 2) = 104201058105.43 / 1.2952183794233E+14;
  check_inverse_matrix(3, 3) = 674771816413.93 / 1.2952183794233E+14;
  check_inverse_matrix(3, 4) = -175713853808.82 / 1.2952183794233E+14;
  check_inverse_matrix(4, 0) = -2234940453411.7 / 1.2952183794233E+14;
  check_inverse_matrix(4, 1) = 1050043528991.2 / 1.2952183794233E+14;
  check_inverse_matrix(4, 2) = 27855846600.084 / 1.2952183794233E+14;
  check_inverse_matrix(4, 3) = -122149073122.39 / 1.2952183794233E+14;
  check_inverse_matrix(4, 4) = 39526717652.346 / 1.2952183794233E+14;

  S21Matrix matrix_before = matrix1;
  S21Matrix matrix_inverse = matrix1.InverseMatrix();

  EXPECT_TRUE(matrix_inverse == check_inverse_matrix);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestInverse, TestInverse6) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.getRows(), 5);
  EXPECT_EQ(matrix1.getCols(), 5);

  S21Matrix check_inverse_matrix{5, 5};
  EXPECT_EQ(check_inverse_matrix.getRows(), 5);
  EXPECT_EQ(check_inverse_matrix.getCols(), 5);

  matrix1(0, 0) = 54.5;
  matrix1(0, 1) = 255.5;
  matrix1(0, 2) = 24.5;
  matrix1(0, 3) = 23.5;
  matrix1(0, 4) = 0.0;
  matrix1(1, 0) = 523.3;
  matrix1(1, 1) = 534.2;
  matrix1(1, 2) = 342.4;
  matrix1(1, 3) = 0.0;
  matrix1(1, 4) = 532.3;
  matrix1(2, 0) = 543.2;
  matrix1(2, 1) = 34.3;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 241.3;
  matrix1(2, 4) = 3423.4;
  matrix1(3, 0) = 3625.2;
  matrix1(3, 1) = 0.0;
  matrix1(3, 2) = 3244.0;
  matrix1(3, 3) = 24.4;
  matrix1(3, 4) = 4365.2;
  matrix1(4, 0) = 0.0;
  matrix1(4, 1) = 231.2;
  matrix1(4, 2) = 2314.2;
  matrix1(4, 3) = 1234.1;
  matrix1(4, 4) = 213.2;

  check_inverse_matrix(0, 0) = 8441832269136.3 / 1.2952183794233E+14;
  check_inverse_matrix(0, 1) = -3963589030994.7 / 1.2952183794233E+14;
  check_inverse_matrix(0, 2) = 17086706405.892 / 1.2952183794233E+14;
  check_inverse_matrix(0, 3) = 478403017840.19 / 1.2952183794233E+14;
  check_inverse_matrix(0, 4) = -173550858290.05 / 1.2952183794233E+14;
  check_inverse_matrix(1, 0) = -1860988589140.3 / 1.2952183794233E+14;
  check_inverse_matrix(1, 1) = 1115918880674.1 / 1.2952183794233E+14;
  check_inverse_matrix(1, 2) = -7728325041.456 / 1.2952183794233E+14;
  check_inverse_matrix(1, 3) = -131948153477.35 / 1.2952183794233E+14;
  check_inverse_matrix(1, 4) = 39557257614.576 / 1.2952183794233E+14;
  check_inverse_matrix(2, 0) = -6523983407620.5 / 1.2952183794233E+14;
  check_inverse_matrix(2, 1) = 3062517351997 / 1.2952183794233E+14;
  check_inverse_matrix(2, 2) = -57361768020.684 / 1.2952183794233E+14;
  check_inverse_matrix(2, 3) = -335401997736.92 / 1.2952183794233E+14;
  check_inverse_matrix(2, 4) = 142078286562.88 / 1.2952183794233E+14;
  check_inverse_matrix(3, 0) = 12968602437721 / 1.2952183794233E+14;
  check_inverse_matrix(3, 1) = -6133333912636.1 / 1.2952183794233E+14;
  check_inverse_matrix(3, 2) = 104201058105.43 / 1.2952183794233E+14;
  check_inverse_matrix(3, 3) = 674771816413.93 / 1.2952183794233E+14;
  check_inverse_matrix(3, 4) = -175713853808.82 / 1.2952183794233E+14;
  check_inverse_matrix(4, 0) = -2234940453411.7 / 1.2952183794233E+14;
  check_inverse_matrix(4, 1) = 1050043528991.2 / 1.2952183794233E+14;
  check_inverse_matrix(4, 2) = 27855846600.084 / 1.2952183794233E+14;
  check_inverse_matrix(4, 3) = -122149073122.39 / 1.2952183794233E+14;
  check_inverse_matrix(4, 4) = 39526717652.346 / 1.2952183794233E+14;

  S21Matrix matrix_before = matrix1;
  S21Matrix matrix_inverse = matrix1.InverseMatrix();

  EXPECT_TRUE(matrix_inverse == check_inverse_matrix);
  EXPECT_TRUE(matrix1 == matrix_before);
}
