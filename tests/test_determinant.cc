#include <gtest/gtest.h>
#include "test_helper.h"

TEST(TestDeterminant, TestDeterminant1) {
  S21Matrix matrix1(4, 4);
  EXPECT_EQ(matrix1.getRows(), 4);
  EXPECT_EQ(matrix1.getCols(), 4);

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(3, 0) = 7.95983747509308;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(3, 1) = -3.41600720770657;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;
  matrix1(3, 2) = -10.6065054496285;
  matrix1(0, 3) = 0.586602877592668;
  matrix1(1, 3) = 10.6546861075331;
  matrix1(2, 3) = 4.33103069034405;
  matrix1(3, 3) = 8.75408579711802;

  double result_check = -6618.5495718153;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, test_helper::eps);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant2) {
  S21Matrix matrix1(9, 9);
  EXPECT_EQ(matrix1.getRows(), 9);
  EXPECT_EQ(matrix1.getCols(), 9);

  matrix1(0, 0) = -0.93;
  matrix1(0, 1) = 0.96;
  matrix1(0, 2) = 0.56;
  matrix1(0, 3) = 0.05;
  matrix1(0, 4) = -0.94;
  matrix1(0, 5) = 0.01;
  matrix1(0, 6) = 0.69;
  matrix1(0, 7) = -1.70;
  matrix1(0, 8) = 0.21;
  matrix1(1, 0) = -1.68;
  matrix1(1, 1) = 0.11;
  matrix1(1, 2) = -0.34;
  matrix1(1, 3) = -1.74;
  matrix1(1, 4) = -0.13;
  matrix1(1, 5) = -0.79;
  matrix1(1, 6) = -0.56;
  matrix1(1, 7) = -1.84;
  matrix1(1, 8) = 1.86;
  matrix1(2, 0) = -1.37;
  matrix1(2, 1) = 0.23;
  matrix1(2, 2) = -0.60;
  matrix1(2, 3) = -1.65;
  matrix1(2, 4) = -1.91;
  matrix1(2, 5) = -0.90;
  matrix1(2, 6) = -0.38;
  matrix1(2, 7) = 0.82;
  matrix1(2, 8) = 1.05;
  matrix1(3, 0) = -1.77;
  matrix1(3, 1) = 1.66;
  matrix1(3, 2) = 0.17;
  matrix1(3, 3) = 0.55;
  matrix1(3, 4) = 1.93;
  matrix1(3, 5) = -0.89;
  matrix1(3, 6) = -0.08;
  matrix1(3, 7) = 1.34;
  matrix1(3, 8) = 1.74;
  matrix1(4, 0) = 0.23;
  matrix1(4, 1) = 1.96;
  matrix1(4, 2) = -0.33;
  matrix1(4, 3) = -1.73;
  matrix1(4, 4) = 0.25;
  matrix1(4, 5) = 1.22;
  matrix1(4, 6) = -0.36;
  matrix1(4, 7) = 1.16;
  matrix1(4, 8) = 1.07;
  matrix1(5, 0) = 0.25;
  matrix1(5, 1) = -0.83;
  matrix1(5, 2) = -1.90;
  matrix1(5, 3) = 0.10;
  matrix1(5, 4) = 0.26;
  matrix1(5, 5) = -1.38;
  matrix1(5, 6) = -0.52;
  matrix1(5, 7) = -0.97;
  matrix1(5, 8) = -0.01;
  matrix1(6, 0) = 1.28;
  matrix1(6, 1) = -1.70;
  matrix1(6, 2) = 1.32;
  matrix1(6, 3) = -1.35;
  matrix1(6, 4) = 0.18;
  matrix1(6, 5) = -0.66;
  matrix1(6, 6) = 1.16;
  matrix1(6, 7) = -0.81;
  matrix1(6, 8) = -1.06;
  matrix1(7, 0) = 0.87;
  matrix1(7, 1) = 1.66;
  matrix1(7, 2) = 0.12;
  matrix1(7, 3) = -1.83;
  matrix1(7, 4) = -1.25;
  matrix1(7, 5) = 0.41;
  matrix1(7, 6) = 1.21;
  matrix1(7, 7) = -1.95;
  matrix1(7, 8) = 0.08;
  matrix1(8, 0) = 1.92;
  matrix1(8, 1) = 1.96;
  matrix1(8, 2) = -1.64;
  matrix1(8, 3) = -0.44;
  matrix1(8, 4) = 1.36;
  matrix1(8, 5) = 0.74;
  matrix1(8, 6) = -0.67;
  matrix1(8, 7) = -1.03;
  matrix1(8, 8) = 1.60;

  double result_check = -63.322314761722227635;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, test_helper::eps);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant3) {
  S21Matrix matrix1(2, 2);
  EXPECT_EQ(matrix1.getRows(), 2);
  EXPECT_EQ(matrix1.getCols(), 2);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  double result_check = -0.02;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, test_helper::eps);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantZero4) {
  S21Matrix matrix1(5, 5);
  EXPECT_EQ(matrix1.getRows(), 5);
  EXPECT_EQ(matrix1.getCols(), 5);

  matrix1(0, 0) = 561;
  matrix1(0, 1) = 356;
  matrix1(0, 2) = 356;
  matrix1(0, 3) = -952;
  matrix1(0, 4) = -506;

  matrix1(1, 0) = 370;
  matrix1(1, 1) = 356;
  matrix1(1, 2) = 356;
  matrix1(1, 3) = 441;
  matrix1(1, 4) = 919;

  matrix1(2, 0) = 113;
  matrix1(2, 1) = 356;
  matrix1(2, 2) = 356;
  matrix1(2, 3) = 577;
  matrix1(2, 4) = -770;

  matrix1(3, 0) = -629;
  matrix1(3, 1) = 356;
  matrix1(3, 2) = 356;
  matrix1(3, 3) = 370;
  matrix1(3, 4) = -226;

  matrix1(4, 0) = 964;
  matrix1(4, 1) = 356;
  matrix1(4, 2) = 356;
  matrix1(4, 3) = 907;
  matrix1(4, 4) = 679;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, test_helper::eps);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant5) {
  S21Matrix matrix1(1, 1);
  EXPECT_EQ(matrix1.getRows(), 1);
  EXPECT_EQ(matrix1.getCols(), 1);

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, test_helper::eps);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminantException1) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
  EXPECT_TRUE(test_matrix == matrix_before);
}