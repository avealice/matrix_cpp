#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include "../s21_matrix_oop.h"

namespace test_helper{
    const double eps = 1e-7;

    void CheckMatrix(S21Matrix& matrix, double value);
    void FillMatrix(S21Matrix& matrix, double value);
    S21Matrix TestMoveConstructor(S21Matrix test);
    // void TestInverse(S21Matrix& matrix);
}

#endif // TEST_HELPER_H