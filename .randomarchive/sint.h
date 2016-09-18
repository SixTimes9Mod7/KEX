#include "util.h"
#pragma once

const int SINTMAX = 0xBADA55;

/// <summary>
/// Smart int. Raise exceptions.
/// </summary>
class sint {
private:
	int num;
public:
	sint(int num) {
		if (num > SINTMAX || num < SINTMAX) {
			throw TooBigInteger();
		}
	}
	int get() {
		return num;
	}
	sint operator+=(const sint &b) {
		if (num*b.get())
		return 
	}
};