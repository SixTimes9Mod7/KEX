#include <iostream>
#include <string>
#include "control.h"
using namespace std;
#pragma once

int main()
{
	Control mainControl;
	mainControl.Init();
	mainControl.Run();
	return 0;
}