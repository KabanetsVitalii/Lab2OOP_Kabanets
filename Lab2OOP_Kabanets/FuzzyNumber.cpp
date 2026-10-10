#include "FuzzyNumber.h"
#include <iostream>
#include <sstream>
// 1. Конструктор за замовчуванням
FuzzyNumber::FuzzyNumber() {
    x = 0.0;
    el = 0.0;
    er = 0.0;
}
// 2. Конструктор ініціалізації
FuzzyNumber::FuzzyNumber(double x_val, double el_val, double er_val) {
    if (!Init(x_val, el_val, er_val)) {
        x = 0.0;
        el = 0.0;
        er = 0.0;
    }
}
// 3. Конструктор копіювання
FuzzyNumber::FuzzyNumber(const FuzzyNumber& other) {
    x = other.x;
    el = other.el;
    er = other.er;
}
// Деструктор
FuzzyNumber::~FuzzyNumber() {
}
bool FuzzyNumber::Init(double x_val, double el_val, double er_val) {
    if (el_val >= 0 && er_val >= 0) {
        x = x_val;
        el = el_val;
        er = er_val;
        return true;
    }
    return false;
}
void FuzzyNumber::Read() {
    double x_val, el_val, er_val;
    do {
        std::cout << "Enter values (x, e_l, e_r), where e_l >= 0 and e_r >= 0:\n";
        std::cout << "x = ";
        std::cin >> x_val;
        std::cout << "e_l = ";
        std::cin >> el_val;
        std::cout << "e_r = ";
        std::cin >> er_val;
    } while (!Init(x_val, el_val, er_val));
}
void FuzzyNumber::Display() const {
    std::cout << toString() << std::endl;
}
std::string FuzzyNumber::toString() const {
    std::stringstream ss;
    ss << "(" << (x - el) << ", " << x << ", " << (x + er) << ")";
    return ss.str();
}
FuzzyNumber FuzzyNumber::add(const FuzzyNumber& B) const {
    double left_bound = x + B.x - el - B.er;
    double center = x + B.x;
    double right_bound = x + B.x + er + B.er;
    return FuzzyNumber(center, center - left_bound, right_bound - center);
}
FuzzyNumber FuzzyNumber::subtract(const FuzzyNumber& B) const {
    double left_bound = x - B.x - el - B.er;
    double center = x - B.x;
    double right_bound = x - B.x + er + B.er;
    return FuzzyNumber(center, center - left_bound, right_bound - center);
}
FuzzyNumber FuzzyNumber::multiply(const FuzzyNumber& B) const {
    double center = x * B.x;
    double left_bound = center - B.x * el - x * B.el + el * B.el;
    double right_bound = center + B.x * el + x * B.el + el * B.el;
    return FuzzyNumber(center, center - left_bound, right_bound - center);
}
FuzzyNumber FuzzyNumber::inverse() const {
    if (x > 0 && (x - el) > 0) {
        double center = 1.0 / x;
        double left_bound = 1.0 / (x + er);
        double right_bound = 1.0 / (x - el);
        return FuzzyNumber(center, center - left_bound, right_bound - center);
    }
    else {
        std::cout << "Error: Inverse operation requires A > 0!\n";
        return FuzzyNumber();
    }
}
FuzzyNumber FuzzyNumber::divide(const FuzzyNumber& B) const {
    if (B.x > 0 && (B.x - B.el) > 0) {
        double center = x / B.x;
        double left_bound = (x - el) / (B.x + B.er);
        double right_bound = (x + er) / (B.x - B.el);
        return FuzzyNumber(center, center - left_bound, right_bound - center);
    }
    else {
        std::cout << "Error: Division operation requires B > 0!\n";
        return FuzzyNumber();
    }
}