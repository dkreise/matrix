#pragma once

#include "Vector.hpp"
#include "Matrix.hpp"

#include <vector>
#include <cmath>

namespace linal {
    // template <typename T>
    // class Vector;
    
    // template <typename T>
    // class Matrix;

    /*** EX 01 ***/

    template <typename T>
    Vector<T> linear_combination(const std::vector<Vector<T>>& u, const std::vector<T>& coefs) {
        if (u.size() != coefs.size() || u.empty()) {
            throw std::invalid_argument("Vectors and coefficients must be of the same non-zero size.");
        }

        size_t vec_size = u[0].size();
        Vector<T> result(vec_size, T{});
        for (size_t i = 0; i < u.size(); i++) {
            if (u[i].size() != vec_size) {
                throw std::invalid_argument("All vectors must be of the same size.");
            }
            result = result + (u[i] * coefs[i]);
        }
        return result;
    }

    /*** EX 02 ***/

    // u * (1.0f - t) + v * t  OR  u + (v - u) * t
    template <typename T>
    T lerp(const T& u, const T&v, float t) {
        if (t < 0.0f || t > 1.0f) {
            throw std::out_of_range("t must be in the range [0, 1].");
        }
        // return std::fma(v - u, t, u);
        return u + (v - u) * t;
    }
}
