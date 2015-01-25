#include "Types.h"
#pragma once

class MakeKex
{
public:
	MakeKex(Control *aprt);
	~MakeKex();

	void Make(int prm);
private:
	Control *prt;
};

