
#include <cstdlib>
#include <ctime>

#include "randomInt.h"

RandomInt::RandomInt(int defaultRangeLow, int defaultRangeHigh) :
		low(defaultRangeLow), high(defaultRangeHigh) {
	int seed = static_cast<int>(time(0));
	srand(seed);
}

int RandomInt::operator()(int rangeLow, int rangeHigh, int multipleOf) const {
	int first(rangeLow + rand() % (rangeHigh - rangeLow + 1));
	int second(first / multipleOf);
	return second * multipleOf;
}
