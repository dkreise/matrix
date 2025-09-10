#include "../../inc/linal.hpp"

void print_test_vec(const Matrix<float>& m, const Vector<float>& v) {
    m.print("M");
    v.print("v");
    try {
        Vector<float> result = m.mul_vec(v);
        result.print("M * v");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

void print_test_mat(const Matrix<float>& a, const Matrix<float>& b) {
    a.print("A");
    b.print("B");
    try {
        Matrix<float> result = a.mul_mat(b);
        result.print("A * B");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::cout << "=== MATRIX MULTIPLICATION ===" << std::endl << std::endl;

    Matrix<float> m({
        {1.0f, 0.0f},
        {0.0f, 1.0f}
    });
    Vector<float> v({4.0f, 2.0f});
    print_test_vec(m, v);

    m = m * 2.0f;
    print_test_vec(m, v);

    m = Matrix<float>({
        {2.0f, -2.0f},
        {-2.0f, 2.0f}
    });
    print_test_vec(m, v);

    Matrix<float> a({
        {1.0f, 0.0f},
        {0.0f, 1.0f}
    });
    Matrix<float> b({
        {1.0f, 0.0f},
        {0.0f, 1.0f}
    });
    print_test_mat(a, b);

    b = Matrix<float>({
        {2.0f, 1.0f},
        {4.0f, 2.0f}
    });
    print_test_mat(a, b);

    a = Matrix<float>({
        {3.0f, -5.0f},
        {6.0f, 8.0f}
    });
    print_test_mat(a, b);

    return 0; 
}
