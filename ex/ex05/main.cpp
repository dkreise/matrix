#include "../../inc/linal.hpp"

void print_test(const Vector<float>& u, const Vector<float>& v) {
    u.print("u");
    v.print("v");
    try {
        float cos_angle = linal::angle_cos(u, v);
        std::cout << "cos(u, v) = " << cos_angle << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    std::cout << "=== COSINE ===" << std::endl << std::endl;

    Vector<float> u({1.0f, 0.0f});
    Vector<float> v({1.0f, 0.0f});
    print_test(u, v); // angle is 0 degrees, cos = 1

    v = Vector<float>({0.0f, 1.0f});
    print_test(u, v); // angle is 90 degrees, cos = 0

    u = Vector<float>({-1.0f, 1.0f});
    v = Vector<float>({1.0f, -1.0f});
    print_test(u, v); // angle is 180 degrees, cos = -1

    u = Vector<float>({2.0f, 1.0f});
    v = Vector<float>({4.0f, 2.0f});
    print_test(u, v); // angle is 0 degrees, cos = 1

    u = Vector<float>({1.0f, 2.0f, 3.0f});
    v = Vector<float>({4.0f, 5.0f, 6.0f});
    print_test(u, v);

    u = Vector<float>({0.0f, 0.0f, 0.0f});
    print_test(u, v);
    
    return 0; 
}
