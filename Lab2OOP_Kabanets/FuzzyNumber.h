#ifndef FUZZYNUMBER_H
#define FUZZYNUMBER_H
#include <string>

class FuzzyNumber {
private:
    double x;  
    double el; 
    double er; 
public:
    // Конструктори та деструктор) 
    FuzzyNumber();                                    // 1. Конструктор за замовчуванням
    FuzzyNumber(double x_val, double el_val, double er_val); // 2. Конструктор ініціалізації
    FuzzyNumber(const FuzzyNumber& other);            // 3. Конструктор копіювання
    ~FuzzyNumber();                                   // Деструктор
    double getX() const { return x; }
    double getEl() const { return el; }
    double getEr() const { return er; }
    void setX(double value) { x = value; }
    void setEl(double value) { el = value; }
    void setEr(double value) { er = value; }
    bool Init(double x_val, double el_val, double er_val);
    void Read();
    void Display() const;
    std::string toString() const;
    // Арифметичні операції 
    FuzzyNumber add(const FuzzyNumber& B) const;
    FuzzyNumber subtract(const FuzzyNumber& B) const;
    FuzzyNumber multiply(const FuzzyNumber& B) const;
    FuzzyNumber inverse() const;
    FuzzyNumber divide(const FuzzyNumber& B) const;
};
#endif // FUZZYNUMBER_H