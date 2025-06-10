//
// 12adi45@gmail.com
//
#include <iostream>
#include "SquareMat.h"

using namespace matrix;

void demoArithmetic(const SquareMat& A, const SquareMat& B) {
    std::cout << "\n--- Arithmetic actions ---\n";
    std::cout << "A + B:\n" << (A + B);
    std::cout << "A - B:\n" << (A - B);
    std::cout << "A * B:\n" << (A * B);
    std::cout << "A * 2:\n" << (A * 2);
    std::cout << "A % 3:\n" << (A % 3);
}

void demoAdvancedOps(SquareMat A) {
    std::cout << "\n---  Advanced operation ---\n";
    std::cout << "A ^ 2:\n" << (A ^ 2);
    std::cout << "Transpose of A:\n" << (~A);
    ++A;
    std::cout << "++A:\n" << A;
    A--;
    std::cout << "A--:\n" << A;
    std::cout << "Determinant of A: " << !A << std::endl;
    SquareMat minor = A.getMinor(0, 1);
    std::cout << "Minor of A (0,1):\n" << minor;
}

void demoComparisons(const SquareMat& A, SquareMat B) {
    std::cout << "\n--- Comparisons ---\n";
    std::cout << "A == B? " << (A == B ? "Yes" : "No") << std::endl;
    std::cout << "A < B?  " << (A < B ? "Yes" : "No") << std::endl;
}

int main() {
    try {
        // יצירת מטריצות ודוגמה ראשונית
        SquareMat A(2);
        SquareMat B(2);

        A[0][0] = 1; A[0][1] = 2;
        A[1][0] = 3; A[1][1] = 4;

        B[0][0] = 5; B[0][1] = 6;
        B[1][0] = 7; B[1][1] = 8;

        std::cout << "matrix A:\n" << A;
        std::cout << "matrix B:\n" << B;

        demoArithmetic(A, B);
        demoAdvancedOps(A);
        demoComparisons(A, B);

    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
    }
    return 0;
}
