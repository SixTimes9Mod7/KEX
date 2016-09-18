#include <string>
#pragma once
using namespace std;

class Kex {
private:
	int db;
public:
	Kex(): db(0) {};
	Kex(int adb): db(adb) {};


	int getDB();
	void addDB(int num);
	void remDB(int num);
	string getName();
};