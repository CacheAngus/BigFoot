
#include <iostream>
#include <string>
using namespace std;

#include "safeArray.h"

SafeArrayException::SafeArrayException(const string& m) : message(m) {}
string& SafeArrayException::what() {
	return message;
}

MyArray::MyArray(int s) : size(s) {
	values = new int[size];
	for (int i = 0; i < size; i++)
		values[i] = 0;
}

MyArray::MyArray(const int v[], int s) : size(s) {
	values = new int[size];
	for (int i = 0; i < size; i++)
		values[i] = v[i];
}

MyArray::~MyArray() {
	delete[] values;
}

int& MyArray::operator[](int index) {
	if (index >= size || index < 0)
		throw SafeArrayException("Index out of bounds.");
	return values[index];
}

int MyArray::operator[](int index) const {
	if (index >= size || index < 0)
		throw SafeArrayException("Index out of bounds.");
	return values[index];
}

ostream& operator<<(ostream& out, const MyArray& sa) {
	out << "SafeArray Contents:" << endl;
	for (int i = 0; i < sa.size; i++)
		out << sa.values[i] << "\t";
	out << endl;
	return out;
}
