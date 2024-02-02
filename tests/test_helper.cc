#include <gtest/gtest.h>
#include "test_helper.h"

namespace test_helper {
    void FillMatrix(S21Matrix& matrix, double value) {
        for (int i = 0; i < matrix.getRows(); i++) {
            for (int j = 0; j < matrix.getCols(); j++) {
                matrix(i, j) = value;
            }
        }
    }

    void CheckMatrix(S21Matrix& matrix, double value) {
        for (int i = 0; i < matrix.getRows(); i++) {
            for (int j = 0; j < matrix.getCols(); j++) {
                ASSERT_NEAR(matrix(i, j), value, test_helper::eps);
            }
        }
    }

    S21Matrix TestMoveConstructor(S21Matrix test) { return test; }

    // void TestInverse(const S21Matrix& matrix) {
    //     S21Matrix matrix_before = matrix;
    //     double det = s21Matrix::matrix.Determinant();
    //     if (std::abs(det) < test_helper::eps) {
    //         EXPECT_ANY_THROW(matrix.InverseMatrix());
    //     } else {
    //         S21Matrix matrix_inverse = matrix.InverseMatrix();
    //         S21Matrix matrix_mult = matrix * matrix_inverse;
    //         S21Matrix matrix_identity =
    //             test_helper::GetIdentityMatrix(matrix.getRows());
    //         EXPECT_TRUE(matrix_mult == matrix_identity);
    //     }
    //     EXPECT_TRUE(matrix == matrix_before);
    // }
}