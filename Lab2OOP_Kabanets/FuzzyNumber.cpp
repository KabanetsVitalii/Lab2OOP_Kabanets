#include "FuzzyNumber.h"
#include <iostream>
#include <sstream>

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
    //  (x - e_l, x, x + e_r)
    ss << "(" << (x - el) << ", " << x << ", " << (x + er) << ")";
    return ss.str();
}
// A + B = (A + B - a_l - b_r, A + B, A + B + a_r + b_r)
FuzzyNumber FuzzyNumber::add(const FuzzyNumber& B) const {
    FuzzyNumber result;
    double left_bound = x + B.x - el - B.er;
    double center = x + B.x;
    double right_bound = x + B.x + er + B.er;

    double new_el = center - left_bound;
    double new_er = right_bound - center;
    result.Init(center, new_el, new_er);
    return result;
}
// A - B = (A - B - a_l - b_r, A - B, A - B + a_r + b_r)
FuzzyNumber FuzzyNumber::subtract(const FuzzyNumber& B) const {
    FuzzyNumber result;
    double left_bound = x - B.x - el - B.er;
    double center = x - B.x;
    double right_bound = x - B.x + er + B.er;
    double new_el = center - left_bound;
    double new_er = right_bound - center;
    result.Init(center, new_el, new_er);
    return result;
}
// A * B = (A * B - B * a_l - A * b_l + a_l * b_l,  A * B,  A * B + B * a_l + A * b_l + a_l * b_l)
FuzzyNumber FuzzyNumber::multiply(const FuzzyNumber& B) const {
    FuzzyNumber result;
    double center = x * B.x;
    double left_bound = center - B.x * el - x * B.el + el * B.el;
    double right_bound = center + B.x * el + x * B.el + el * B.el;
    double new_el = center - left_bound;
    double new_er = right_bound - center;
    result.Init(center, new_el, new_er);
    return result;
}
// 1 / A = (1 / (A + a_r), 1 / A, 1 / (A - a_l)), A > 0
FuzzyNumber FuzzyNumber::inverse() const {
    FuzzyNumber result;
    if (x > 0 && (x - el) > 0) {
        double center = 1.0 / x;
        double left_bound = 1.0 / (x + er);
        double right_bound = 1.0 / (x - el);
        double new_el = center - left_bound;
        double new_er = right_bound - center;
        result.Init(center, new_el, new_er);
    }
    else {
        std::cout << "Error: Inverse operation requires A > 0!\n";
        result.Init(0, 0, 0);
    }
    return result;
}
// A / B = ((A - a_l) / (B + b_r), A / B, (A + a_r) / (B - b_l)), B > 0
FuzzyNumber FuzzyNumber::divide(const FuzzyNumber& B) const {
    FuzzyNumber result;
    if (B.x > 0 && (B.x - B.el) > 0) {
        double center = x / B.x;
        double left_bound = (x - el) / (B.x + B.er);
        double right_bound = (x + er) / (B.x - B.el);
        double new_el = center - left_bound;
        double new_er = right_bound - center;
        result.Init(center, new_el, new_er);
    }
    else {
        std::cout << "Error: Division operation requires B > 0!\n";
        result.Init(0, 0, 0);
    }
    return result;
}