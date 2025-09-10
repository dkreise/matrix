#include "../../inc/linal.hpp"

void print_test(const Vector<float>& u, const Vector<float>& v) {
    u.print("u");
    v.print("v");
    try {
        Vector<float> cross = linal::cross_product(u, v);
        cross.print("u x v");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::cout << "=== CROSS PRODUCT ===" << std::endl << std::endl;

    Vector<float> u({0.0f, 0.0f, 1.0f});
    Vector<float> v({1.0f, 0.0f, 0.0f});
    print_test(u, v);

    u = Vector<float>({1.0f, 2.0f, 3.0f});
    v = Vector<float>({4.0f, 5.0f, 6.0f});
    print_test(u, v);

    u = Vector<float>({4.0f, 2.0f, -3.0f});
    v = Vector<float>({-2.0f, -5.0f, 16.0f});
    print_test(u, v);
    
    return 0; 
}
