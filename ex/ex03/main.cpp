#include "../../inc/linal.hpp"

void print_test(const Vector<float>& u, const Vector<float>& v) {
    u.print("u");
    v.print("v");
    try {
        float result = u.dot(v);
        std::cout << "u . v = " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::cout << "=== DOT PRODUCT ===" << std::endl << std::endl;

    Vector<float> u({0.0f, 0.0f});
    Vector<float> v({1.0f, 1.0f});
    print_test(u, v);

    u = Vector<float>({1.0f, 1.0f});
    print_test(u, v);

    u = Vector<float>({-1.0f, 6.0f});
    v = Vector<float>({3.0f, 2.0f});
    print_test(u, v);

    u = Vector<float>({1.0f, 2.0f, 3.0f});
    print_test(u, v);

    return 0;
}
