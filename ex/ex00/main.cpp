#include "../../inc/Vector.hpp"
#include "../../inc/Matrix.hpp"

int main() {
    Vector<int> v = Vector<int>(5, 42);
    v.print();
    std::cout << std::endl;
    Vector<int> v2 = Vector<int>({1, 22, 333});
    v2.print();
    std::cout << std::endl;
    Matrix<int> m = Matrix<int>(2, 3, 4242);
    m.print();
    std::cout << std::endl;
    Matrix<int> m2 = Matrix<int>(2, 3, {1, 22, 3333, 4, 5, 62});
    m2.print();

    return 0;
}