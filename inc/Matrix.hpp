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
};
