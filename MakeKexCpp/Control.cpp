#include "EatKex.h"
#include "MakeKex.h"
#include "Control.h"
#include <iostream>
#include <string>
using namespace std;

Control::Control()
{
	kex = 0;
	isRun = false;
	mk = 0;
	ek = 0;
}
Control::~Control()
{
	delete mk;
	delete ek;
}

void Control::Init()
{
	mk = new MakeKex(this);
	ek = new EatKex(this);
}

void Control::Run()
{
	cout << "1: make kex, 2: eat kex, 9: status, 8: exit\n";

	isRun = true;
	while (isRun)
	{
		string read;
		getline(cin, read);
		int op = atoi(read.c_str());
		int prm = 0;
		if (read.find(' ') != 0) prm = atoi(read.c_str() + read.find(' '));
		if (op == 9)
		{
			cout << "You have " << kex << " kexes.\n";
		}
		else if (op == 1)
		{
			mk->Make(prm);
		}
		else if (op == 2)
		{
			ek->Eat(prm);
		}
		else if (op == 8)
		{
			Stop();
		}
	}
}