#include "../../inc/Complex.hpp"
#include "../../inc/linal.hpp"

int main() {
    std::cout << "=== COMPLEX VECTOR SPACE ===" << std::endl << std::endl;
    
    std::cout << "--- VECTOR OPERATIONS ---" << std::endl << std::endl;

    Vector<Complex> v1({Complex(1.5, 0.0), Complex(2.5, 1.2), Complex(3.5, 8.0)});
    Vector<Complex> v2({Complex(-4.0, 3.0), Complex(5.0, -2.0), Complex(6.2, 1.0)});
    v1.print("v1");
    v2.print("v2");

    v1.add(v2);
    v1.print("v1.add(v2)");
    v1.sub(v2);
    v1.print("v1.sub(v2)");
    v1.scl(Complex(2.0, -2.0));
    v1.print("v1.scl(2-2i)");
}
