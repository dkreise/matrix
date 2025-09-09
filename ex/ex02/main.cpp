#include "../../inc/linal.hpp"

int main() {
    std::cout << "=== LINEAR INTERPOLATION ===" << std::endl << std::endl;

    float a = 0.0f;
    float b = 1.0f;
    float t = 0.0f;
    std::cout << "u = " << a << std::endl << "v = " << b << std::endl;
    std::cout << "t = " << t << std::endl;
    std::cout << "lerp(u, v, t) = " << linal::lerp(a, b, t) << std::endl;
    t = 1.0f;
    std::cout << "t = " << t << std::endl;
    std::cout << "lerp(u, v, t) = " << linal::lerp(a, b, t) << std::endl;
    t = 0.5f;
    std::cout << "t = " << t << std::endl;
    std::cout << "lerp(u, v, t) = " << linal::lerp(a, b, t) << std::endl << std::endl;

    a = 21.0f;
    b = 42.0f;
    t = 0.3f;
    std::cout << "u = " << a << std::endl << "v = " << b << std::endl;
    std::cout << "t = " << t << std::endl;
    std::cout << "lerp(u, v, t) = " << linal::lerp(a, b, t) << std::endl << std::endl;

    Vector<float> u{2.0f, 1.0f};
    Vector<float> v{4.0f, 2.0f};
    t = 0.3f;
    u.print("u");
    v.print("v");
    std::cout << "t = " << t << std::endl;
    Vector<float> result = linal::lerp(u, v, t);
    result.print("lerp(u, v, t)");
    std::cout << std::endl;

    Matrix<float> m1({
        {2.0f, 1.0f},
        {3.0f, 4.0f}
    });
    Matrix<float> m2({
        {20.0f, 10.0f},
        {30.0f, 40.0f}
    });
    t = 0.5f;
    m1.print("M1");
    m2.print("M2");
    std::cout << "t = " << t << std::endl;
    Matrix<float> m_result = linal::lerp(m1, m2, t);
    m_result.print("lerp(M1, M2, t)");

    return 0;
}
