#include "../../inc/Vector.hpp"
#include "../../inc/Matrix.hpp"

int main() {
    Vector<int> v = Vector<int>(5, 42);
    std::cout << v;
    Matrix<int> m = Matrix<int>(2, 3, 4242);
    m.print();
    Matrix<int> m2 = Matrix<int>(2, 3, {1, 22, 3333, 4, 5, 62});
    m2.print();

    return 0;
}