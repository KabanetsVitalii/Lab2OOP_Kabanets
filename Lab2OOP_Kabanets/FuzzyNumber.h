#ifndef FUZZYNUMBER_H
#define FUZZYNUMBER_H
#include <string>

class FuzzyNumber {
private:
    double x;  // Center value
    double el; // Left error (e_l)
    double er; // Right error (e_r)
public:
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

    FuzzyNumber add(const FuzzyNumber& B) const;
    FuzzyNumber subtract(const FuzzyNumber& B) const;
    FuzzyNumber multiply(const FuzzyNumber& B) const;
    FuzzyNumber inverse() const;
    FuzzyNumber divide(const FuzzyNumber& B) const;
};

#endif 