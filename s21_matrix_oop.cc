#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ < 0 || cols_ < 0) {
    throw std::length_error("Matrix size cannot be negative");
  }
  matrix_ = new double[rows_ * cols_]();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_),
      cols_(other.cols_),
      matrix_(new double[rows_ * cols_]()) {
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() noexcept {
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

int S21Matrix::getRows() { return rows_; }

int S21Matrix::getCols() { return cols_; }

void S21Matrix::freeMatrix() noexcept {
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

void S21Matrix::setRows(int new_rows) {
  if (new_rows < 0) {
    throw std::length_error("Matrix size cannot be negative");
  } else if (rows_ == new_rows) {
    return;
  }
  S21Matrix tmp(new_rows, cols_);
  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i < rows_) {
        tmp.matrix_[i * cols_ + j] = matrix_[i * cols_ + j];
      } else {
        tmp.matrix_[i * cols_ + j] = 0.0;
      }
    }
  }
  freeMatrix();
  cols_ = tmp.cols_;
  rows_ = tmp.rows_;
  matrix_ = tmp.matrix_;
  tmp.matrix_ = nullptr;
}

void S21Matrix::setCols(int new_cols) {
  if (new_cols < 0) {
    throw std::length_error("Matrix size cannot be negative");
  } else if (cols_ == new_cols) {
    return;
  }
  S21Matrix tmp(rows_, new_cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < new_cols; j++) {
      if (j < cols_) {
        tmp.matrix_[i * new_cols + j] = matrix_[i * cols_ + j];
      } else {
        tmp.matrix_[i * new_cols + j] = 0.0;
      }
    }
  }
  freeMatrix();
  cols_ = tmp.cols_;
  rows_ = tmp.rows_;
  matrix_ = tmp.matrix_;
  tmp.matrix_ = nullptr;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::abs(matrix_[i * cols_ + j] - other.matrix_[i * cols_ + j]) > eps)
        return false;
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Incorrect matrix size for sum");
  }
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i * cols_ + j] += other.matrix_[i * cols_ + j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Incorrect matrix size for sub");
  }
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i * cols_ + j] -= other.matrix_[i * cols_ + j];
    }
  }
}

void S21Matrix::MulNumber(const double number) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i * cols_ + j] *= number;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::logic_error("Incorrect matrix size for mul");
  }
  S21Matrix res_matrix(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        res_matrix(i, j) +=
            matrix_[i * cols_ + k] * other.matrix_[k * cols_ + j];
        // res_matrix(i, j) += (*this)(i,)
      }
    }
  }
  *this = std::move(res_matrix);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res_matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res_matrix(j, i) = (*this)(i, j);
    }
  }
  return res_matrix;
}

S21Matrix S21Matrix::MinorMatrix(int remove_row, int remove_col) {
  S21Matrix res_matrix(rows_ - 1, cols_ - 1);
  int row = 0;
  for (int i = 0; i < rows_; i++) {
    int col = 0;
    for (int j = 0; j < cols_; j++) {
      if (i != remove_row && j != remove_col) {
        res_matrix(row, col) = (*this)(i, j);
        col++;
      }
    }
    if (i != remove_row) row++;
  }
  return res_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect matrix size");
  }
  S21Matrix res_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor_matrix = MinorMatrix(i, j);
      double determinant = minor_matrix.Determinant();
      res_matrix(i, j) = determinant * pow(-1, i + j);
    }
  }
  return res_matrix;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect matrix size");
  }
  double determinant = 0.0;
  if (rows_ == 1) {
    determinant = (*this)(0, 0);
  } else if (rows_ == 2) {
    determinant = (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
  } else {
    int sign = 1;
    for (int i = 0; i < rows_; i++) {
      S21Matrix minor_matrix = MinorMatrix(0, i);
      determinant += sign * (*this)(0, i) * minor_matrix.Determinant();
      sign = -sign;
    }
  }
  return determinant;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (determinant == 0) {
    throw std::logic_error("Determinant must be non-zero to calculate inverse");
  }
  return Transpose().CalcComplements() * (1.0 / determinant);
}

// ==============================================================
// Оператор умножения и присвоение умножения
// ==============================================================

S21Matrix S21Matrix::operator*(double number) const noexcept {
  S21Matrix tmp(*this);
  tmp.MulNumber(number);
  return tmp;
}

S21Matrix& S21Matrix::operator*=(double number) {
  MulNumber(number);
  return *this;
}

S21Matrix operator*(double number, const S21Matrix& matrix) noexcept {
  S21Matrix tmp = matrix * number;
  return tmp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

// ==============================================================
// Оператор сложения и присвоение сложения
// ==============================================================

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

// ==============================================================
// Оператор вычитания и присвоение вычитания
// ==============================================================

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

// ==============================================================
// Оператор присвоения
// ==============================================================

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  S21Matrix copy(other);
  *this = std::move(copy);
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    freeMatrix();
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

// ==============================================================
// Оператор равенства
// ==============================================================

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

// ==============================================================
// Оператор скобочки
// ==============================================================

double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Index is out of range");
  }
  return matrix_[row * cols_ + col];
}
