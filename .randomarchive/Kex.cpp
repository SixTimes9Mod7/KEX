#include "Kex.h"


int Kex::getDB() {
	return db;
}

void Kex::addDB(int num) {
	db += num;
}

void Kex::remDB(int num) {
	db -= num;
}

string Kex::getName() {
	return "";
}
