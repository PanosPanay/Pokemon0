#pragma once
#include "pokemon.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
const int winExp = 80;//赢的宠物小精灵经验值增加80
const int loseExp = 50;//输的宠物小精灵经验值增加50
const int tieExp = 60;//平局增加的经验值

class FIGHT {
public:
	POKEMON	A;
	POKEMON	B;

	FIGHT();
	FIGHT(POKEMON F1, POKEMON F2);
	FIGHT(const FIGHT &theFight);
	void A_VS_B();
};
