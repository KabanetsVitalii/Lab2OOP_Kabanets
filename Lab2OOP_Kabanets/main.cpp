#include <iostream>
#include "FuzzyNumber.h"

int main() {
    // 1. Демонстрація конструктора за замовчуванням
    FuzzyNumber defObj;
    std::cout << "Default Constructor object : ";
    defObj.Display();
    // 2. Демонстрація конструктора ініціалізації
    FuzzyNumber A(5.0, 1.0, 2.0);
    std::cout << "Init Constructor object A: ";
    A.Display();
    // 3. Демонстрація конструктора копіювання
    FuzzyNumber copyA(A);
    std::cout << "Copy Constructor object copyA (from A): ";
    copyA.Display();
    // Робота звичайного введення та арифметики
    FuzzyNumber B;
    std::cout << "\n Enter Fuzzy Number B ";
    B.Read();
    std::cout << "Number B: ";
    B.Display();
    std::cout << "\nArithmetic Operations";
    FuzzyNumber sum = A.add(B);
    std::cout << "A + B = ";
    sum.Display();
    return 0;
}