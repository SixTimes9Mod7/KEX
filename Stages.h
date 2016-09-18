#pragma once
#include "Player.h"
#include "Types.h"

class Stage {
protected:
	Commander* cm;
	Control* co;
public:
	Stage();
	virtual ~Stage();

	virtual void Load(Commander*, Control*);
	virtual void Close() = 0;
protected:
	virtual void Init() = 0;
};

class Stage0: public Stage {
public:
	virtual void Close();
protected:
	virtual void Init();
};

class Stage1: public Stage {
public:
	virtual void Close();
protected:
	virtual void Init();
};