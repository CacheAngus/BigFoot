#include <iostream>
#include <cmath>
using namespace std;

#include "myComplex.h"

MyComplex::MyComplex() : real(0), imag(0) { }
MyComplex::MyComplex(double r) : real(r), imag(0) { }
MyComplex::MyComplex(double r, double im) : real(r), imag(im) { }

double MyComplex::getReal() const { return real; }
double MyComplex::getImag() const { return imag; }

double MyComplex::abs() const {
	return sqrt(real * real + imag * imag);
}

// Accesssors are not used here
MyComplex MyComplex::operator+(const MyComplex& right) const {
	return MyComplex(real + right.real, imag + right.imag);
}

ostream& operator<<(ostream& out, const MyComplex& value) {
   out << value.getReal() << " + " << value.getImag() << "i";
   return out;
}
