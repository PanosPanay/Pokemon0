#pragma once
#include "pokemon.h"
const int winExp = 80;//Ӯ�ĳ���С���龭��ֵ����80
const int loseExp = 50;//��ĳ���С���龭��ֵ����50
const int tieExp = 60;//ƽ�����ӵľ���ֵ

class FIGHT {
public:
	POKEMON	A;
	POKEMON	B;

	FIGHT();
	//FIGHT(POKEMON A, POKEMON B);
	FIGHT(const FIGHT &theFight);
	void A_VS_B();
};
