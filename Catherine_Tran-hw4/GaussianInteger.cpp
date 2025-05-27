#include "GaussianInteger.h"

GaussianInteger::GaussianInteger() : ComplexNumber(0,0) {}
GaussianInteger::GaussianInteger(const int real, const int imag) : ComplexNumber(real,imag) {}
GaussianInteger::GaussianInteger(const GaussianInteger &other) : ComplexNumber(other.getReal(), other.getImag()) {}

ComplexNumber* GaussianInteger::add(const ComplexNumber &other) {
    int thisreal = getReal(), otherreal = other.getReal();
    int thisimag = getImag(), otherimag = other.getImag();
    int newreal = thisreal + otherreal;
    int newimag = thisimag + otherimag;
    ComplexNumber* sum = new GaussianInteger(newreal,newimag);
    return sum;
}

ComplexNumber* GaussianInteger::multiply(const ComplexNumber &other)  {
    int thisreal = getReal(), otherreal = other.getReal();
    int thisimag = getImag(), otherimag = other.getImag();
    int newreal = (thisreal*otherreal) - (thisimag*otherimag);
    int newimag = (thisreal*otherimag) + (thisimag*otherreal);
    ComplexNumber* prod = new GaussianInteger(newreal,newimag);
    return prod;
}

ComplexNumber* GaussianInteger::conjugate() {
    int thisreal = getReal(), thisimag = getImag();
    ComplexNumber* conj = new GaussianInteger(thisreal,thisimag*-1);
    return conj;
}

bool GaussianInteger::divides(const GaussianInteger &other) {
    int othernorm = (other.getReal()*other.getReal()) + (other.getImag()*other.getImag());
    if (othernorm==0) return false;
    int r = real*other.getReal() + imag*other.getImag();
    int i = imag*other.getReal() - real*other.getImag();
    return r%othernorm==0 && i%othernorm==0;
}

int GaussianInteger::norm() {
    return (real*real) + (imag*imag);
}

GaussianInteger GaussianInteger::operator+(const GaussianInteger &other) const {
    int thisreal = getReal(), otherreal = other.getReal();
    int thisimag = getImag(), otherimag = other.getImag();
    int newreal = thisreal + otherreal;
    int newimag = thisimag + otherimag;
    return GaussianInteger(newreal,newimag);
}

GaussianInteger GaussianInteger::operator*(const GaussianInteger &other) const {
    int thisreal = getReal(), otherreal = other.getReal();
    int thisimag = getImag(), otherimag = other.getImag();
    int newreal = (thisreal*otherreal) - (thisimag*otherimag);
    int newimag = (thisreal*otherimag) + (thisimag*otherreal);
    return GaussianInteger(newreal,newimag);
}

bool GaussianInteger::operator==(const GaussianInteger &other) const {
    int thisreal = getReal(), otherreal = other.getReal();
    int thisimag = getImag(), otherimag = other.getImag();
    return thisreal==otherreal && thisimag==otherimag;
}

std::ostream& operator<<(std::ostream& os, const GaussianInteger& other) {
    int oreal = other.getReal();
    int oimag = other.getImag();
    if (oimag<0) os << oreal << " - " << abs(oimag) << "i";
    else os << oreal << " + " << oimag << "i";
    return os;
}