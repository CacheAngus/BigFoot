#include <iostream>
using namespace std;

#include "randomInt.h"

int main() {

	RandomInt r(10, 100);
	cout << &r << ", size: " << sizeof(r) << endl;
	cout << "Between 10 and 100: " << r() << ", " << r() << ", " << r() << endl;
	cout << "Between 10 and 1000: " << r(1000) << ", " << r(1000) << ", " << r(1000) << endl;
	cout << "Between 1 and 10: " << r(1, 10) << ", " << r(1, 10) << ", " << r(1, 10) << endl;
	cout << "Between 20 and 2000, multiples of 5: " << r(20, 2000, 5) << ", " << r(20, 2000, 5) << ", " << r(20, 2000, 5) << endl;

	return 0;
}
