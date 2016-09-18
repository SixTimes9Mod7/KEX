#include "Stages.h"
#include "Player.h"
#include "util.h"
#include <iostream>
using namespace std;

Stage::Stage() {}

Stage::~Stage() {}

void Stage::Load(Commander* acm, Control* aco) {
	cm = acm;
	co = aco;
	Init();
}

void Stage0::Close() {}

void Stage0::Init() {
	
}

void Stage1::Close() {}

void Stage1::Init() {}
