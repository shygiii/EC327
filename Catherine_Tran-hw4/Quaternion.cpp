#include "Quaternion.h"
using namespace std;

Quaternion::Quaternion() : GaussianInteger(0,0), j(0), k(0) {}
Quaternion::Quaternion(const int real, const int imag, const int j, const int k) : GaussianInteger(real,imag), j(j), k(k) {}
Quaternion::Quaternion(const Quaternion &other) : GaussianInteger(other.getReal(),other.getImag()), j(other.j), k(other.k) {}

ComplexNumber* Quaternion::add(const ComplexNumber &other) {
    const Quaternion* check = dynamic_cast<const Quaternion*>(&other);
    if (!check) {
        std::cerr << "The other object is not a Quaternion!" << std::endl;
        return nullptr;
    }
    int thisreal = real, otherreal = other.getReal();
    int thisimag = imag, otherimag = other.getImag();
    int thisk = k, otherk = check->getK();
    int thisj = j, otherj = check->getJ();
    int newreal = thisreal + otherreal;
    int newimag = thisimag + otherimag;
    int newj = thisj+otherj;
    int newk = thisk+otherk;
    ComplexNumber* summed = new Quaternion(newreal,newimag,newj,newk);
    return summed;
}

ComplexNumber* Quaternion::multiply(const ComplexNumber &other) {
    const Quaternion* check = dynamic_cast<const Quaternion*>(&other);
    if (!check) {
        std::cerr << "The other object is not a Quaternion!" << std::endl;
        return nullptr;
    }    
    int w1 = real, w2 = check->getReal();
    int x1 = imag, x2 = check->getImag();
    int y1 = j, y2 = check->getJ();
    int z1 = k, z2 = check->getK();

    int realcoef = (w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2);
    int icoef = (w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2);
    int jcoef = (w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2);
    int kcoef = (w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2);
    ComplexNumber* prod = new Quaternion(realcoef,icoef,jcoef,kcoef);
    return prod;
}

ComplexNumber* Quaternion::conjugate() {
    int oreal = getReal();
    int oimag = getImag();
    int oj = getJ();
    int ok = getK();
    ComplexNumber* conj = new Quaternion(real, -oimag, -oj, -ok);
    return conj;
}

std::ostream &operator<<(std::ostream &os, const Quaternion &other) {
    int oreal = other.getReal();
    int oimag = other.getImag();
    int oj = other.getJ();
    int ok = other.getK();

    os << oreal;
    if (oimag < 0) os << " - " << abs(oimag) << "i";
    else os << " + " << oimag << "i";

    if (oj < 0) os << " - " << abs(oj) << "j";
    else os << " + " << oj << "j";

    if (ok < 0) os << " - " << abs(ok) << "k";
    else os << " + " << ok << "k";
    return os;
}