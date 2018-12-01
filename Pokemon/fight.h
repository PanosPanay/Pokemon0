#pragma once
#include "pokemon.h"
const int winExp = 80;//赢的宠物小精灵经验值增加80
const int loseExp = 50;//输的宠物小精灵经验值增加50
const int tieExp = 60;//平局增加的经验值

class FIGHT {
public:
	POKEMON	A;
	POKEMON	B;

	FIGHT();
	//FIGHT(POKEMON A, POKEMON B);
	FIGHT(const FIGHT &theFight);
	void A_VS_B();
};
