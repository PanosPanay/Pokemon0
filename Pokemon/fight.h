#pragma once
#include "pokemon.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
const int winExp = 80;//Ӯ�ĳ���С���龭��ֵ����80
const int loseExp = 50;//��ĳ���С���龭��ֵ����50
const int tieExp = 60;//ƽ�����ӵľ���ֵ

class FIGHT {
public:
	POKEMON	A;
	POKEMON	B;

	FIGHT();
	FIGHT(POKEMON F1, POKEMON F2);
	FIGHT(const FIGHT &theFight);
	void A_VS_B();
};
