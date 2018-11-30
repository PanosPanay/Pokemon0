#include "pokemon.h"

POKEMON::POKEMON()
{
	//kind，Name没必要赋初值
	Rank = 0;
	Exp = 0;
	// Atk 初值？
	//Def
	//Hp
	//AtkInterval
}

POKEMON::POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk, int xdef, int xhp, int xatki)
{
	Kind = xkind;
	Name = xname;
	Rank = xrank;
	Exp = xexp;
	Atk = xatk;
	Def = xdef;
	Hp = xhp;
	AtkInterval = xatki;
}

POKEMON::POKEMON(const POKEMON & PET)
{
}

POKEMON::~POKEMON()
{
}

void POKEMON::Input_Kind(POKEMONKIND xkind)
{
}

POKEMONKIND POKEMON::Get_Kind()
{
	return POKEMONKIND();
}

void POKEMON::Input_Name(string xname)
{
}

string POKEMON::Get_Name()
{
	return string();
}

void POKEMON::Input_Rank(int xrank)
{
}

int POKEMON::Get_Rank()
{
	return 0;
}

void POKEMON::Input_Exp(int xexp)
{
}

int POKEMON::Get_Exp()
{
	return 0;
}

void POKEMON::Input_Atk(int xatk)
{
}

int POKEMON::Get_Atk()
{
	return 0;
}

void POKEMON::Input_Def(int xdef)
{
}

int POKEMON::Get_Def()
{
	return 0;
}

void POKEMON::Input_Hp(int xhp)
{
}

int POKEMON::Get_Hp()
{
	return 0;
}

void POKEMON::Input_AtkI(int xatki)
{
}

int POKEMON::Get_AtkI()
{
	return 0;
}
