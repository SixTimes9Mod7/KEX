#include "util.h"
#include <string>
#include <iostream>
using namespace std;

int Parser::str2int(const string &s) {
	long long r = 0;
	int sgn = 1;
	int i = 0;
	while (s[i] == ' ') ++i;
	if (s[i] == '-') sgn = -1, ++i;
	for (i; i < s.length(); ++i) {
		if ('0' <= s[i] && s[i] <= '9') {
			long long nr = r * 10 + (s[i] - '0');
			if (nr > MAXSAFE) throw exception("Too big number");
			else r = nr;
		} else {
			if(s[i] == ' ') break;
			else throw exception("Illegal character");
		}
	}
	return int(r) * sgn;
}

Parser::Parser(istream * aist): ist(aist) {}
void Parser::setInput(istream * aist) { ist = aist; }
istream * Parser::getInput() { return ist; }

void Parser::readLine() {
	bool error;
	do {
		try {
			error = false;
			string inp;
			cout << ">>> ";
			getline(*ist, inp);
			string scom = "", spar = "";
			int p = 0;
			while (p < inp.length() && p == ' ') p++;
			while (p < inp.length() && p != ' ') scom += inp[p++];
			while (p < inp.length() && p == ' ') p++;
			while (p < inp.length() && p != ' ') spar += inp[p++];
			com = str2int(scom);
			par = str2int(spar);
		} catch (const exception & e) {
			cout << "ERROR: " << e.what() << ". Enter numbers again.\n";
			error = true;
		}
	} while (error);
}
int Parser::getLastCommand() { return com; }
int Parser::getLastParam() { return par; }
