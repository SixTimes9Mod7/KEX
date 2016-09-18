#pragma once
#include "Types.h"

class Control
{
private:
	Stage* currentStage;
	Player* player;
public:
	Control();
	~Control();

	void Hello();
	void LoadStage(Stage*);
	void Run();
};

struct Command {
	virtual ~Command() = 0;
	virtual Stage* execute(int par) = 0;
};

class Commander {
private:
	int comn[1024];
	Command* coms[1024];
public:
	void addCommand(int num, Command* c);
	void setCommand(int num, Command* c);
	void remCommand(int num);
};