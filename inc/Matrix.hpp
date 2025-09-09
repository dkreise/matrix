#pragma once

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

        T& operator()(size_t i, size_t j) {
            return data[i * ncols + j];
        }
        const T& operator()(size_t i, size_t j) const {
            return data[i * ncols + j];
        }

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
                std::cout << "[";
                for (size_t j = 0; j < ncols; j++) {
                    std::cout << std::left << std::setw(width) << operator()(i, j);
                    if (j < ncols - 1) {
                        std::cout << " ";
                    }
                }
                std::cout << "]" << std::endl;
            }
        }
};
