#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(): kex(0), hp(100), mana(100) {}
Player::Player(int kex, int hp, int mana) : kex(kex), hp(hp), mana(mana) {};
