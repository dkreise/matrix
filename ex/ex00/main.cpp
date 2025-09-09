#include "../../inc/Vector.hpp"
#include "../../inc/Matrix.hpp"

int main() {
    std::cout << "=== VECTOR OPERATIONS ===" << std::endl << std::endl;

    Vector<float> v1({1.5, 2.5, 3.5});
    Vector<float> v2({4.0, 5.0, 6.0});
    v1.print("v1");
    v2.print("v2");

    Vector<float> v3 = v1 + v2;
    v3.print("v1 + v2");

    Vector<float> v4 = v2 - v1;
    v4.print("v2 - v1");

    Vector<float> v5 = v1 * 2.0;
    v5.print("v1 * 2.0");

    v1.add(v2);
    v1.print("v1.add(v2)");

    v1.sub(v2);
    v1.print("v1.sub(v2)");

    v1.scl(3.0);
    v1.print("v1.scl(3.0)");

    std::cout << std::endl << "=== MATRIX OPERATIONS ===" << std::endl << std::endl;

    Matrix<float> m1({
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    });
    Matrix<float> m2({
        {9.0, 8.8, 7.3},
        {6.2, 5.9, 4.0}
    });
    m1.print("M1");
    m2.print("M2");

    Matrix<float> m3 = m1 + m2;
    m3.print("M1 + M2");

    Matrix<float> m4 = m2 - m1;
    m4.print("M2 - M1");

    Matrix<float> m5 = m1 * 2.0;
    m5.print("M1 * 2.0");

    m1.add(m2);
    m1.print("M1.add(M2)");

    m1.sub(m2);
    m1.print("M1.sub(M2)");

    m1.scl(3.0);
    m1.print("M1.scl(3.0)");

    return 0;
}