#include "../../inc/linal.hpp"

void print_test(const Matrix<float>& m) {
    m.print("M");
    std::cout << std::endl;
    try {
        Matrix<float> result = m.row_echelon();
        result.print("M.row_echelon()");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::cout << "=== ROW-ECHELON FORM ===" << std::endl << std::endl;

    Matrix<float> m({
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
    });
    print_test(m);

    m = Matrix<float>({
        {1.0f, 2.0f},
        {3.0f, 4.0f}
    });
    print_test(m);

    m = Matrix<float>({
        {1.0f, 2.0f},
        {2.0f, 4.0f}
    });
    print_test(m);

    m = Matrix<float>({
        {8.0f, 5.0f, -2.0f, 4.0f, 28.0f},
        {4.0f, 2.5f, 20.0f, 4.0f, -4.0f},
        {8.0f, 5.0f, 1.0f, 4.0f, 17.0f},
    });
    print_test(m);

    return 0; 
}
