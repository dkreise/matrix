#include "../../inc/linal.hpp"

void print_test(const std::vector<Vector<float>>& vectors, const std::vector<float>& coefs) {
    std::cout << "Vectors:" << std::endl;
    for (size_t i = 0; i < vectors.size(); i++) {
        vectors[i].print("v" + std::to_string(i + 1));
    }
    std::cout << "Coefficients: ";
    for (const auto& coef : coefs) {
        std::cout << coef << " ";
    }
    std::cout << std::endl;

    try {
        Vector<float> result = linal::linear_combination(vectors, coefs);
        std::cout << "Linear Combination (";
        for (size_t i = 0; i < vectors.size(); i++) {
            std::cout << coefs[i] << "*v" << (i + 1);
            if (i < vectors.size() - 1) {
                std::cout << " + ";
            }
        }
        std::cout << ") = " << std::endl;
        result.print();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== LINEAR COMBINATION ===" << std::endl << std::endl;

    Vector<float> v1({1.0, 2.0, 3.0});
    Vector<float> v2({4.0, 5.0, 6.0});
    Vector<float> v3({7.0, 8.0, 9.0});
    std::vector<Vector<float>> vectors = {v1, v2, v3};
    std::vector<float> coefs = {0.2, 0.3, 0.5};
    print_test(vectors, coefs);

    Vector<float> v4({1.0, 0.0, 0.0});
    Vector<float> v5({0.0, 1.0, 0.0});
    Vector<float> v6({0.0, 0.0, 1.0});
    vectors = {v4, v5, v6};
    coefs = {10.0, -2.0, 0.5};
    print_test(vectors, coefs);

    Vector<float> v7({0.0, 10.0, -100.0});
    vectors = {v1, v7};
    coefs = {10.0, -2.0};
    print_test(vectors, coefs);

    Vector<float> v8({1.0, 2.0});
    vectors = {v1, v8};
    coefs = {1.0, 1.0};
    print_test(vectors, coefs);

    return 0;
}
