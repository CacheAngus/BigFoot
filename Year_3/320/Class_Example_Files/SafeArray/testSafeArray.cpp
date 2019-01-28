#include <iostream>
using namespace std;

#include "safeArray.h"

int main() {

	MyArray test0(10);
	cout << test0;

	MyArray test1(10);
	for(int i = 0; i < 10; i++)
		test1[i] = i;
	cout << test1;

	// Illegal:
	try {
		test1[10] = 20;
	} catch (SafeArrayException& e) {
		cerr << e.what() << endl;
	}

	int nums[] = {10, 20, 30, 40, 50};
	MyArray test2(nums, 5);
	cout << test2;

	// Illegal:
	try {
		cout << test2[5];
	} catch (SafeArrayException& e) {
		cerr << e.what() << endl;
	}

	return 0;
}
