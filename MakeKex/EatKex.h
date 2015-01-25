#include "Types.h"
#pragma once
class EatKex
{
public:
	EatKex(Control *aprt);
	~EatKex();

	void Eat(int num);
private:
	Control* prt;
};

