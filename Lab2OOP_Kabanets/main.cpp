#include <iostream>
#include "FuzzyNumber.h"

int main() {
    FuzzyNumber A, B;
    std::cout << "Enter Fuzzy Number A \n";
    A.Read();
    std::cout << "Number A: ";
    A.Display();
    std::cout << "Enter Fuzzy Number B\n";
    B.Read();
    std::cout << "Number B: ";
    B.Display();

    std::cout << "Arithmetic Operations Results\n";
    FuzzyNumber sum = A.add(B);
    std::cout << "A + B = ";
    sum.Display();
    FuzzyNumber diff = A.subtract(B);
    std::cout << "A - B = ";
    diff.Display();
    FuzzyNumber prod = A.multiply(B);
    std::cout << "A * B = ";
    prod.Display();
    if (A.getX() > 0) {
        FuzzyNumber invA = A.inverse();
        std::cout << "1 / A = ";
        invA.Display();
    }
    if (B.getX() > 0) {
        FuzzyNumber div = A.divide(B);
        std::cout << "A / B = ";
        div.Display();
    }
    return 0;
}