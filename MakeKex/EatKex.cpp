#include "EatKex.h"
#include "Control.h"
#include <iostream>
using namespace std;


EatKex::EatKex(Control *aprt)
{
	prt = aprt;
}
EatKex::~EatKex()
{

}


void EatKex::Eat(int prm)
{
	if (prt->GetKex() == 0)
	{
		cout << "You haven't got kexes!\n";
	}
	else if (prm == 0)
	{
		prt->AddKex(-1);
		cout << "You ate a kex.\n";
	}
	else if (prt->GetKex() <= prm)
	{
		prm = prt->GetKex();
		prt->SetKex(0);
		cout << "You ate " << prm << " kexes.\n";
	}
	else
	{
		prt->AddKex(-prm);
		cout << "You ate " << prm << " kexes.\n";
	}
}
