/*
 * This version of the MyComplex class uses non-member overloading of the + operator
 * and friend functions instead of accessors.
 */
#pragma once

#include <iostream>
using namespace std;

class MyComplex {

public:
	MyComplex();				// Default Constructor
	MyComplex(double);			// Constructor, Conversion Constructor
	MyComplex(double, double);	// Constructor
	double abs() const;			// Accessor
private:
	double real;
	double imag;

// friend Functions
friend MyComplex operator+(const MyComplex& left, const MyComplex& right);
friend ostream& operator<<(ostream& out, const MyComplex& value);
};
