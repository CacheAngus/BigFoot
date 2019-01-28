
#pragma once

#include <iostream>
#include <string>
using namespace std;

class SafeArrayException {
public:
	SafeArrayException(const string&);
	string& what();
private:
	string message;
};

class MyArray {
public:
	MyArray(int);				// Constructor
	MyArray(const int[], int);	// Constructor
	~MyArray();					// Destructor!
	int& operator[](int);		// Overloading [] - use on LHS of =
	int operator[](int) const;	// Overloading [] - use on RHS of =
private:
	int size;
	int* values;
friend ostream& operator<<(ostream&, const MyArray&);
};

