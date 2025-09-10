#include "../../inc/linal.hpp"

void print_test(const Vector<float>& u) {
    u.print("u");
    std::cout << std::endl;
    std::cout << "||u||_1   = " << u.norm_1() << std::endl;
    std::cout << "||u||     = " << u.norm() << std::endl;
    std::cout << "||u||_inf = " << u.norm_inf() << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::cout << "=== NORM ===" << std::endl << std::endl;

    Vector<float> u({0.0f, 0.0f, 0.0f});
    print_test(u);

    u = Vector<float>({1.0f, 2.0f, 3.0f});
    print_test(u);

    u = Vector<float>({-1.0f, -2.0f});
    print_test(u);

    return 0; 
}
