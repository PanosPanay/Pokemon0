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
	//Accuracy
	//Evasiveness
	//wType
	//Skills
	//SkillCnt
}

POKEMON::POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk, int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness, WUXINGTYPE xtype, int xskillcnt)
{
	Kind = xkind;
	Name = xname;
	Rank = xrank;
	Exp = xexp;
	Atk = xatk;
	Def = xdef;
	Hp = xhp;
	AtkInterval = xatki;
	Accuracy = xaccuracy;
	Evasiveness = xevasiveness;
	wType = xtype;
	SkillCnt = xskillcnt;
}

POKEMON::POKEMON(const POKEMON & PET)
{
	Kind = PET.Get_Kind();
	Name = PET.Get_Name();
	Rank = PET.Get_Rank();
	Exp = PET.Get_Exp();
	Atk = PET.Get_Atk();
	Def = PET.Get_Def();
	Hp = PET.Get_Hp();
	AtkInterval = PET.Get_AtkI();
	Accuracy = PET.Get_Accuracy();
	Evasiveness = PET.Get_Evasiveness();
	wType = PET.Get_Type();
	SkillCnt = PET.Get_SkillCnt();
}

POKEMON::~POKEMON()
{
}

void POKEMON::Input_Kind(POKEMONKIND xkind)
{
	Kind = xkind;
}

POKEMONKIND POKEMON::Get_Kind()
{
	return Kind;
}

void POKEMON::Input_Name(string xname)
{
	Name = xname;
}

string POKEMON::Get_Name()
{
	return Name;
}

void POKEMON::Input_Rank(int xrank)
{
	Rank = xrank;
}

int POKEMON::Get_Rank()
{
	return Rank;
}

void POKEMON::Input_Exp(int xexp)
{
	Exp = xexp;
}

int POKEMON::Get_Exp()
{
	return Exp;
}

void POKEMON::Input_Atk(int xatk)
{
	Atk = xatk;
}

int POKEMON::Get_Atk()
{
	return Atk;
}

void POKEMON::Input_Def(int xdef)
{
	Def = xdef;
}

int POKEMON::Get_Def()
{
	return Def;
}

void POKEMON::Input_Hp(int xhp)
{
	Hp = xhp;
}

int POKEMON::Get_Hp()
{
	return Hp;
}

void POKEMON::Input_AtkI(int xatki)
{
	AtkInterval = xatki;
}

int POKEMON::Get_AtkI()
{
	return AtkInterval;
}

void POKEMON::Input_Accuracy(double xaccuracy)
{
	Accuracy = xaccuracy;
}

double POKEMON::Get_Accuracy()
{
	return Accuracy;
}

void POKEMON::Input_Evasiveness(double xevasiveness)
{
	Evasiveness = xevasiveness;
}

double POKEMON::Get_Evasiveness()
{
	return Evasiveness;
}

void POKEMON::Input_Type(WUXINGTYPE xtype)
{
	wType = xtype;
}

WUXINGTYPE POKEMON::Get_Type()
{
	return wType;
}

void POKEMON::Input_SkillCnt(int xskillcnt)
{
	SkillCnt = xskillcnt;
}

int POKEMON::Get_SkillCnt()
{
	return SkillCnt;
}
