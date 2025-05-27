#ifndef GAUSSIANINTEGER_H
#define GAUSSIANINTEGER_H
#include "ComplexNumber.h"
#include <iostream>

class GaussianInteger : public ComplexNumber {
public:
    GaussianInteger();
    GaussianInteger(const int real, const int imag);
    GaussianInteger(const GaussianInteger &other);

    ComplexNumber* add(const ComplexNumber &other) override;
    ComplexNumber* multiply(const ComplexNumber &other) override;
    ComplexNumber* conjugate() override;

    bool divides(const GaussianInteger &other);
    int norm();

    GaussianInteger operator+(const GaussianInteger &other) const;
    GaussianInteger operator*(const GaussianInteger &other) const;
    bool operator==(const GaussianInteger &other) const;
    friend std::ostream& operator<<(std::ostream& os, const GaussianInteger& other);
};
#endif // GAUSSIANINTEGER_H