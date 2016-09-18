#include "MakeKex.h"
#include "Control.h"
#include <iostream>
#include <algorithm>
using namespace std;

MakeKex::MakeKex(Control *aprt)
{
	prt = aprt;
}
MakeKex::~MakeKex()
{

}


void MakeKex::Make(int prm)
{
	if (prm < 0)
	{
		prm = min(-prm, prt->GetKex());
		prt->AddKex(-prm);
		cout << "You destroyed "<< prm <<" kexes.\n";
	}
	else if (prm == 0)
	{
		prt->AddKex(1);
		cout << "You made a kex.\n";
	}
	else
	{
		prt->AddKex(prm);
		cout << "You made " << prm << " kexes.\n";
	}
}
