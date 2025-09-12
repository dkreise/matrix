#include "../../inc/linal.hpp"

void print_test(const Matrix<float>& m) {
    m.print("M");
    std::cout << std::endl;
    try {
        size_t r = m.rank();
        std::cout << "Rank: " << r << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::cout << "=== RANK ===" << std::endl << std::endl;

    Matrix<float> m({
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
    });
    print_test(m);

    m = Matrix<float>({
        {1.0f, 2.0f, 0.0f, 0.0f},
        {2.0f, 4.0f, 0.0f, 0.0f},
        {-1.0f, 2.0f, 1.0f, 1.0f},
    });
    print_test(m);

    m = Matrix<float>({
        {8.0f, 5.0f, -2.0f},
        {4.0f, 7.0f, 20.0f},
        {7.0f, 6.0f, 1.0f},
        {21.0f, 18.0f, 7.0f}
    });
    print_test(m);

    return 0; 
}
