#include "../../inc/Vector.hpp"

int main() {
    Vector<int> v = Vector<int>(5, 42);
    std::cout << v;
    return 0;
}