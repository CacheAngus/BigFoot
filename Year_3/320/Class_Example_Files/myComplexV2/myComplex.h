/*
 * This version uses member overloading of the + operator.
 */
#pragma once

#include <iostream>
using namespace std;

class MyComplex {
public:
	MyComplex();				// Default Constructor
	MyComplex(double);			// Constructor, Conversion Constructor
	MyComplex(double, double);	// Constructor
	double getReal() const;		// Accessor
	double getImag() const;		// Accessor
	double abs() const;			// Accessor
	MyComplex operator+(const MyComplex&) const;	// Member Overloading of +
private:
	double real;
	double imag;
};

// Non-Member overloading of <<
ostream& operator<<(ostream& out, const MyComplex& value);

