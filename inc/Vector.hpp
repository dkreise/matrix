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
        Vector(std::initializer_list<T> init) : data(init) {}

        /*** OPERATORS ***/

        T& operator[](size_t i) {
            return data[i];
        }
        const T& operator[](size_t i) const {
            return data[i];
        }
        Vector<T> operator+(const Vector<T>& v) const {
            Vector<T> result = *this;
            result.add(v);
            return result;
        }
        Vector<T> operator-(const Vector<T>& v) const {
            Vector<T> result = *this;
            result.sub(v);
            return result;
        }
        Vector<T> operator*(const T& a) const {
            Vector<T> result = *this;
            result.scl(a);
            return result;
        }

        /*** UTILS ***/

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
                std::cout << "\t[" << std::left << std::setw(width) << data[i] << "]" << std::endl;
            }
        }
        void print(const std::string& name) const {
            std::cout << name << " = " << std::endl;
            print();
        }

        /*** EX 00 ***/

        void add(const Vector<T>& v) {
            if (size() != v.size()) {
                throw std::invalid_argument("Vectors must be of the same size for addition.");
            }
            for (size_t i = 0; i < size(); i++) {
                data[i] += v[i];
            }
        }

        void sub(const Vector<T>& v) {
            if (size() != v.size()) {
                throw std::invalid_argument("Vectors must be of the same size for subtraction.");
            }
            for (size_t i = 0; i < size(); i++) {
                data[i] -= v[i];
            }
        }

        void scl(const T& a) {
            for (size_t i = 0; i < size(); i++) {
                data[i] *= a;
            }
        }
};
