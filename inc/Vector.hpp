#pragma once

#include <iostream>
#include <vector>
#include <iomanip>

template <typename T>
class Vector {
    private:
        std::vector<T> data;

    public:
        Vector() {}
        Vector(size_t n, T value = T{}) : data(n, value) {}
        Vector(const std::vector<T>& values) : data(values) {}

        T& operator[](size_t i) {
            return data[i];
        }
        const T& operator[](size_t i) const {
            return data[i];
        }

        size_t size() const {
            return data.size();
        }

        void print() const {
            size_t width = 0;
            for (auto& val : data) {
                std::ostringstream oss;
                oss << val;
                width = std::max(width, oss.str().size());
            }

            for (size_t i = 0; i < size(); i++) {
                std::cout << "[" << std::left << std::setw(width) << data[i] << "]" << std::endl;
            }
        }
};

// template <typename T>
// std::ostream & operator<<(std::ostream & o, Vector<T> const & v) {
//     for (size_t i = 0; i < v.size(); i++) {
//         o << "[" << v[i] << "]" << std::endl;
//     }
// 	return (o);
// }
