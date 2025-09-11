#include "../../inc/linal.hpp"

void print_test(const Matrix<float>& m) {
    m.print("M");
    std::cout << std::endl;
    try {
        Matrix<float> result = m.transpose();
        result.print("M.transpose()");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::cout << "=== TRANSPOSE ===" << std::endl << std::endl;

    Matrix<float> m({
        {1.0f, 0.0f},
        {0.0f, 1.0f}
    });
    print_test(m);

    m = Matrix<float>({
        {2.0f, -5.0f, 0.0f},
        {4.0f, 3.0f, 7.0f},
        {-2.0f, 3.0f, 4.0f}
    });
    print_test(m);

    m = Matrix<float>({
        {1.0f, 2.0f, 3.0f, 4.0f},
        {5.0f, 6.0f, 7.0f, 8.0f}
    });
    print_test(m);

    return 0; 
}
