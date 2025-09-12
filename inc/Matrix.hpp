#pragma once

#include "Vector.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

template <typename T>
class Matrix {
    private:
        std::vector<T> data;
        size_t nrows;
        size_t ncols;

    public:
        Matrix() : nrows(0), ncols(0) {}
        Matrix(size_t r, size_t c, T value = T{}) : data(r * c, value), nrows(r), ncols(c) {}
        Matrix(size_t r, size_t c, const std::vector<T>& values) : data(values), nrows(r), ncols(c) {
            if (values.size() != r * c) {
                throw std::invalid_argument("Size of values does not match matrix dimensions");
            }
        }
        Matrix(const std::vector<std::vector<T>>& values) {
            nrows = values.size();
            ncols = values.empty() ? 0 : values[0].size();
            data.reserve(nrows * ncols);
            for (const auto& row : values) {
                if (row.size() != ncols) {
                    throw std::invalid_argument("All rows must have the same number of columns");
                }
                data.insert(data.end(), row.begin(), row.end());
            }
        }

        /*** OPERATORS ***/

        T& operator()(size_t i, size_t j) {
            return data[i * ncols + j];
        }
        const T& operator()(size_t i, size_t j) const {
            return data[i * ncols + j];
        }
        Matrix<T> operator+(const Matrix<T>& m) const {
            Matrix<T> result = *this;
            result.add(m);
            return result;
        }
        Matrix<T> operator-(const Matrix<T>& m) const {
            Matrix<T> result = *this;
            result.sub(m);
            return result;
        }
        Matrix<T> operator*(const T& a) const {
            Matrix<T> result = *this;
            result.scl(a);
            return result;
        }

        /*** UTILS ***/

        size_t rows() const {
            return nrows;
        }
        size_t cols() const {
            return ncols;
        }
        bool isSquare() const {
            return nrows == ncols;
        }
        void print() const {
            // find maximum width
            size_t width = 0;
            for (auto& val : data) {
                std::ostringstream oss;
                oss << val;
                width = std::max(width, oss.str().size());
            }

            for (size_t i = 0; i < nrows; i++) {
                std::cout << "   [";
                for (size_t j = 0; j < ncols; j++) {
                    std::cout << std::left << std::setw(width) << operator()(i, j);
                    if (j < ncols - 1) {
                        std::cout << " ";
                    }
                }
                std::cout << "]" << std::endl;
            }
        }
        void print(const std::string& name) const {
            std::cout << name << " = " << std::endl;
            print();
        }

        /*** EX 00 ***/

        void add(const Matrix<T>& m) {
            if (nrows != m.rows() || ncols != m.cols()) {
                throw std::invalid_argument("Matrices must have the same dimensions for addition.");
            }
            for (size_t i = 0; i < data.size(); i++) {
                data[i] += m.data[i];
            }
        }

        void sub(const Matrix<T>& m) {
            if (nrows != m.rows() || ncols != m.cols()) {
                throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
            }
            for (size_t i = 0; i < data.size(); i++) {
                data[i] -= m.data[i];
            }
        }

        void scl(const T& a) {
            for (size_t i = 0; i < data.size(); i++) {
                data[i] *= a;
            }
        }

        /*** EX 07 ***/

        Vector<T> mul_vec(const Vector<T>& v) const {
            if (ncols != v.size()) {
                throw std::invalid_argument("Matrix columns must match vector size for multiplication.");
            }

            Vector<T> result(nrows, T{});
            for (size_t i = 0; i < nrows; i++) {
                T sum = T{};
                for (size_t j = 0; j < ncols; j++) {
                    sum = std::fma(operator()(i, j), v[j], sum);
                }
                result[i] = sum;
            }
            return result;
        }

        Matrix<T> mul_mat(const Matrix<T>& m) const {
            if (ncols != m.rows()) {
                throw std::invalid_argument("Matrix A columns must match Matrix B rows for multiplication.");
            }

            Matrix<T> result(nrows, m.cols(), T{});
            for (size_t i = 0; i < nrows; i++) {
                for (size_t j = 0; j < m.cols(); j++) {
                    T sum = T{};
                    for (size_t k = 0; k < ncols; k++) {
                        sum = std::fma(operator()(i, k), m(k, j), sum);
                    }
                    result(i, j) = sum;
                }
            }
            return result;
        }

        /*** EX 08 ***/

        T trace() const {
            if (!isSquare()) {
                throw std::invalid_argument("Matrix must be square to compute trace.");
            }
            T sum = T{};
            for (size_t i = 0; i < nrows; i++) {
                sum += operator()(i, i);
            }
            return sum;
        }

        /*** EX 09 ***/

        Matrix<T> transpose() const {
            Matrix<T> result(ncols, nrows, T{});
            for (size_t i = 0; i < nrows; i++) {
                for (size_t j = 0; j < ncols; j++) {
                    result(j, i) = operator()(i, j);
                }
            }
            return result;
        }

        /*** EX 10 ***/

        Matrix<T> row_echelon() const {
            Matrix<T> res = *this;
            size_t lead_row = 0;
            for (size_t col = 0; col < ncols && lead_row < nrows; col++) {
                // Find the pivot
                size_t max_row = lead_row;
                for (size_t r = lead_row + 1; r < nrows; r++) {
                    if (std::abs(res(r, col)) > std::abs(res(max_row, col))) {
                        max_row = r;
                    }
                }
                if (std::abs(res(max_row, col)) < 1e-12) {
                    continue; // No pivot in this column
                }

                // Swap to put pivot on the lead row
                if (max_row != lead_row) {
                    for (size_t c = 0; c < ncols; c++) {
                        std::swap(res(lead_row, c), res(max_row, c));
                    }
                }

                // Scale pivot to 1
                T pivot = res(lead_row, col);
                for (size_t c = col; c < ncols; c++) {
                    res(lead_row, c) /= pivot;
                }

                // Eliminate all other rows
                for (size_t r = 0; r < nrows; r++) {
                    if (r != lead_row) {
                        T factor = res(r, col);
                        if (std::abs(factor) < 1e-12) {
                            continue; // No need to eliminate
                        }
                        for (size_t c = col; c < ncols; c++) {
                            res(r, c) -= factor * res(lead_row, c);
                        }
                    }
                }
                lead_row++;
            }
            return res;
        }

        /*** EX 11 ***/

        T determinant() const {
            if (!isSquare() || nrows == 0) {
                throw std::invalid_argument("Matrix must be square to compute determinant.");
            }
            if (nrows > 4) {
                throw std::invalid_argument("Determinant calculation is only implemented for matrices up to 4x4.");
            }

            Matrix<T> m = *this;
            T det = T{1};
            int sign = 1;

            for (size_t i = 0; i < nrows; i++) {
                // Find pivot
                size_t pivot_row = i;
                for (size_t r = i + 1; r < nrows; r++) {
                    if (std::abs(m(r, i)) > std::abs(m(pivot_row, i))) {
                        pivot_row = r;
                    }
                }
                // if pivot is close to zero, determinant is zero
                if (std::abs(m(pivot_row, i)) < 1e-12) {
                    return T{0};
                }

                // Swap rows if needed
                if (pivot_row != i) {
                    for (size_t c = 0; c < ncols; c++) {
                        std::swap(m(i, c), m(pivot_row, c));
                    }
                    sign = -sign;
                }

                // Eliminate below
                for (size_t r = i + 1; r < nrows; r++) {
                    T factor = m(r, i) / m(i, i);
                    for (size_t c = i; c < ncols; c++) {
                        m(r, c) -= factor * m(i, c);
                    }
                }

                det *= m(i, i);
            }

            return sign * det;
        }

        /*** EX 12 ***/

        Matrix<T> inverse() const {
            if (!isSquare() || nrows == 0) {
                throw std::invalid_argument("Matrix must be square to compute inverse.");
            }

            size_t n = nrows;

            // Create augmented matrix [A | I]
            Matrix<T> aug(n, 2 * n, T{});
            for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++) {
                    aug(i, j) = operator()(i, j);
                }
                aug(i, n + i) = T{1};
            }

            // Apply Gauss-Jordan elimination
            for (size_t i = 0; i < n; i++) {
                // Find pivot
                size_t pivot_row = i;
                for (size_t r = i + 1; r < n; r++) {
                    if (std::abs(aug(r, i)) > std::abs(aug(pivot_row, i))) {
                        pivot_row = r;
                    }
                }
                if (std::abs(aug(pivot_row, i)) < 1e-12) {
                    throw std::runtime_error("Matrix is singular and cannot be inverted.");
                }

                // Swap rows if needed
                if (pivot_row != i) {
                    for (size_t c = 0; c < 2 * n; c++) {
                        std::swap(aug(i, c), aug(pivot_row, c));
                    }
                }

                // Scale pivot to 1
                T pivot = aug(i, i);
                for (size_t c = 0; c < 2 * n; c++) {
                    aug(i, c) /= pivot;
                }

                // Eliminate all other rows
                for (size_t r = 0; r < n; r++) {
                    if (r != i) {
                        T factor = aug(r, i);
                        for (size_t c = 0; c < 2 * n; c++) {
                            aug(r, c) -= factor * aug(i, c);
                        }
                    }
                }
            }

            // Extract inverse from augmented matrix
            Matrix<T> inv(n, n, T{});
            for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++) {
                    inv(i, j) = aug(i, n + j);
                }
            }
            return inv;
        }
};
