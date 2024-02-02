#ifndef S21MATRIX_H__
#define S21MATRIX_H__

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <utility>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix() noexcept;

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  double& operator()(int row, int col);
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator*(double number) const noexcept;
  S21Matrix& operator*=(double number);
  friend S21Matrix operator*(double number, const S21Matrix& matrix) noexcept;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double number) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix MinorMatrix(int remove_row, int remove_col);

  int getRows();
  int getCols();
  void setRows(int new_rows);
  void setCols(int new_cols);

 private:
  int rows_, cols_;
  double* matrix_;
  void freeMatrix() noexcept;
  const double eps = 1e-7;
};

#endif  // S21MATRIX_H__s