#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include <iostream>

/**
 * This class represents a complex number A+Bi with the following properties:
 * - It has a constructor that creates a complex number with a real part A and imaginary part Bi,
 * the coefficients of which are represented by real and imag, respectively.
 * - It has member functions that return the real and imaginary parts of the complex number, respectively.
 * - It has pure virtual functions that can be implemented by child classes to perform addition, 
 * multiplication, and conjugation operations on two complex numbers.
 */
class ComplexNumber {
protected:
    int real;
    int imag;

public:
    /**
     * Constructs a ComplexNumber object with a real part r and an imaginary part i.
     */
    ComplexNumber(int r, int i) : real(r), imag(i) {}

    /**
     * @return The real part of the complex number. 
     */
    int getReal() const { return real; }

    /**
     * @return The imaginary part of the complex number. 
     */
    int getImag() const { return imag; }

    /**
     * Returns the sum of the ComplexNumber other and this complex number.
     * @param other The complex number term to be added.
     * @return The sum of the two complex numbers. 
     */
    virtual ComplexNumber *add(const ComplexNumber &other) = 0;
    
    /**
     * Returns the product of the ComplexNumber other and this complex number.
     * @param other The complex number term to be multiplied.
     * @return The product of the two complex numbers. 
     */
    virtual ComplexNumber *multiply(const ComplexNumber &other) = 0;
    
    /**
     * Returns the conjugate of this complex number.
     * @return The sum of the two complex numbers. 
     */
    virtual ComplexNumber *conjugate() = 0;
    
    /**
     * Prints a complex number in the form A + Bi or A - Bi, where A is the absolute value of
     * the int real and B is the absolute value of the int imag. If imag is greater than 0,
     * then A + Bi is printed. Otherwise, A - Bi is printed.
     */
    void print() {
        std::cout << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i"
                  << std::endl;
    }
};
#endif