#pragma once
#include <string>
#include <iostream>
using namespace std;

// 2147483647
// 0xFFFFFFFF
const int MAXSAFE = 1000000007;

class Parser {
public:
	Parser(istream* ist = &cin);
	void setInput(istream* ist);
	istream* getInput();

	void readLine();
	int getLastCommand();
	int getLastParam();
private:
	int com;
	int par;
	istream* ist;
	int str2int(const string &);
};
