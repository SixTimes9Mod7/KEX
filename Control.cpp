#include "Control.h"
#include "util.h"
#include "Stages.h"
#include <windows.h>
#include <iostream>
using namespace std;

Control::Control() {
	player = new Player();
}

Control::~Control() {
	delete player;
}

void Control::Hello() {
	cout << "Welcome to the KEX game.\n";
	Beep(500, 500); Beep(1000, 500); Beep(1500, 300); Beep(1500, 300); Beep(1500, 900);
	cout << "Do you need tutorial? (0: yes, 1: no)\n";
	Parser par;
	par.readLine();
	if (par.getLastCommand() == 0) {
		currentStage = new Stage0;
	} else {
		currentStage = new Stage1;
	}
}

void Control::LoadStage(Stage *) {}

void Control::Run() {

}

void Commander::addCommand(int num, Command* c) {
	for (int i = 1; i < 1024; ++i) {
		if (comn[i] == 0) {
			comn[i] = num;
			coms[i] = c;
		}
	}
}
void Commander::setCommand(int num, Command * c) {
	for (int i = 0; i < 1024; ++i) {
		if (comn[i] == num) {
			delete coms[i];
			coms[i] = c;
		}
	}
}
void Commander::remCommand(int num) {
	for (int i = 1; i < 1024; ++i) {
		if (comn[i] == num) {
			comn[i] = 0;
			delete coms[i];
		}
	}
}
