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

    /*** EX 05 ***/

    template <typename T>
    float angle_cos(const Vector<T>& u, const Vector<T>& v) {
        if (u.size() != v.size() || u.size() == 0) {
            throw std::invalid_argument("Vectors must be of the same non-zero size.");
        }
        T dot_product = u.dot(v);
        float norm_u = u.norm();
        float norm_v = v.norm();
        if (norm_u == 0.0f || norm_v == 0.0f) {
            throw std::domain_error("Cannot compute angle with zero-length vector.");
        }
        return dot_product / (norm_u * norm_v);
    }

    /*** EX 06 ***/

    template <typename T>
    Vector<T> cross_product(const Vector<T>& u, const Vector<T>& v) {
        if (u.size() != 3 || v.size() != 3) {
            throw std::invalid_argument("Both vectors must be 3-dimensional.");
        }
        return Vector<T>({
            u[1] * v[2] - u[2] * v[1],
            u[2] * v[0] - u[0] * v[2],
            u[0] * v[1] - u[1] * v[0]
        });
    }
}
