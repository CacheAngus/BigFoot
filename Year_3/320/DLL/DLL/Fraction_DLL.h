#pragma once

#ifdef DLL_EXPORTS
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_IMPORT __declspec(dllimport)
#endif

#include <iostream>

using namespace std;



class DLL_EXPORT FractionException {
public:
	FractionException(const string&);
	virtual string& what();
private:
	string message;
};

class DLL_EXPORT Fraction {
public:
	// Constructs a fraction with numerator 0 and denominator 1.
	Fraction();

	// Constructs a fraction with numerator t and denominator 1.
	Fraction(int t);

	// Constructs a fraction with given numerator and denominator.
	Fraction(int t, int b);

	// Returns the numerator.
	virtual int numerator() const;

	// Returns the denominator.
	virtual int denominator() const;

	// Updates a fraction by adding in another fraction value.
	Fraction& operator+=(const Fraction& right);

	// Increment fraction by 1.
	Fraction& operator++(); 			// Preincrement form
	Fraction operator++(int unused); // Postincrement form

	// Compare one fraction value to another.
	// Result is negative if less than right, zero if equal, and
	// positive if greater than right.
	virtual int compare(const Fraction& right) const;

private:
	// Place the fraction in lowest common denominator form.
	void normalize();

	// Compute the greatest common denominator of two integer values.
	int gcd(int n, int m);

	int top;			// numerator
	int bottom;		// denominator
};

// Non-member overloaded arithmetic operators
DLL_EXPORT Fraction operator+(const Fraction& left, const Fraction& right);
DLL_EXPORT Fraction operator-(const Fraction& left, const Fraction& right);
DLL_EXPORT Fraction operator*(const Fraction& left, const Fraction& right);
DLL_EXPORT Fraction operator/(const Fraction& left, const Fraction& right);
DLL_EXPORT Fraction operator-(const Fraction& value);

// Non-member overloaded boolean operators
DLL_EXPORT bool operator<(const Fraction& left, const Fraction& right);
DLL_EXPORT bool operator<=(const Fraction& left, const Fraction& right);
DLL_EXPORT bool operator==(const Fraction& left, const Fraction& right);
DLL_EXPORT bool operator!=(const Fraction& left, const Fraction& right);
DLL_EXPORT bool operator>=(const Fraction& left, const Fraction& right);
DLL_EXPORT bool operator>(const Fraction& left, const Fraction& right);

// Non-member stream operators
DLL_EXPORT ostream& operator<<(ostream& out, const Fraction& value);
DLL_EXPORT istream& operator>>(istream& in, Fraction& retFrac);
