#include "../../inc/Complex.hpp"
#include "../../inc/linal.hpp"

int main() {
    std::cout << "=== COMPLEX VECTOR SPACE ===" << std::endl << std::endl;
    
    {
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

    {
        std::cout << std::endl << "--- LINEAR COMBINATION ---" << std::endl << std::endl;

        Vector<Complex> v1({Complex(1.0, 1.0), Complex(0.0, -1.0), Complex(-1.0, 0.0)});
        Vector<Complex> v2({Complex(2.0, 0.0), Complex(0.0, 4.0), Complex(2.0, 1.0)});
        Vector<Complex> v3({Complex(0.0, 3.0), Complex(2.0, 0.0), Complex(2.0, -5.0)});
        std::vector<Vector<Complex>> vectors = {v1, v2, v3};
        std::vector<Complex> coefs = {Complex(1.0, 0.0), Complex(0.0, 1.0), Complex(1.0, -1.0)};
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
            Vector<Complex> result = linal::linear_combination(vectors, coefs);
            result.print("Result");
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    {
        std::cout << std::endl << "--- LINEAR INTERPOLATION ---" << std::endl << std::endl;

        Vector<Complex> u{Complex(1.0, 0.0), Complex(0.0, 1.0)};
        Vector<Complex> v{Complex(4.0, 0.0), Complex(0.0, 4.0)};
        float t = 0.25f;
        u.print("u");
        v.print("v");
        std::cout << "t = " << t << std::endl;
        Vector<Complex> result = linal::lerp(u, v, t);
        result.print("lerp(u, v, t)");
    }

    // {
    //     std::cout << std::endl << "--- DOT PRODUCT ---" << std::endl << std::endl;

    //     Vector<Complex> u({Complex(1.0, 2.0), Complex(3.0, 4.0)});
    //     Vector<Complex> v({Complex(5.0, 6.0), Complex(7.0, 8.0)});
    //     u.print("u");
    //     v.print("v");
    //     try {
    //         Complex result = u.dot(v);
    //         std::cout << "u . v = " << result << std::endl;
    //     } catch (const std::invalid_argument& e) {
    //         std::cerr << "Error: " << e.what() << std::endl;
    //     }
    // }

    std::cout << std::endl;
    return 0;
}
