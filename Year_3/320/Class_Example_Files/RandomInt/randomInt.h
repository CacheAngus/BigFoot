#pragma once

#include <cstdlib>

class RandomInt {
public:
	RandomInt(int defaultRangeLow, int defaultRangeHigh);
	int operator()() const;
	int operator()(int rangeHigh) const;
	int operator()(int rangeLow, int rangeHigh) const;
	// This one is a bit silly, but it does prove that you can have more than two parameters:
	int operator()(int rangeLow, int rangeHigh, int multipleOf) const;
private:
	int low;
	int high;
};

inline int RandomInt::operator()() const {
	return low + rand() % (high - low + 1);
}

inline int RandomInt::operator()(int rangeHigh) const {
	return low + rand() % (rangeHigh - low + 1);
}

inline int RandomInt::operator()(int rangeLow, int rangeHigh) const {
	return rangeLow + rand() % (rangeHigh - rangeLow + 1);
}

