#include <iostream>
#include <cmath>
using namespace std;

#include "myComplex.h"

MyComplex::MyComplex() : real(0), imag(0) { }
MyComplex::MyComplex(double r) : real(r), imag(0) { }
MyComplex::MyComplex(double r, double im) : real(r), imag(im) { }

double MyComplex::abs() const {
	return sqrt(real * real + imag * imag);
}

MyComplex operator+(const MyComplex& left, const MyComplex& right) {
	//real = -1000;		// Can we get at the attributes of MyComplex from a friend?
	return MyComplex(left.real + right.real, left.imag + right.imag);
}

ostream& operator<<(ostream& out, const MyComplex& value) {
   out << value.real << " + " << value.imag << "i";
   return out;
}
