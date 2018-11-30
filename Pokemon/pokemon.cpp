#include "pokemon.h"

POKEMON::POKEMON()
{
	//kind，Name没必要赋初值
	Rank = 1;
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
	//Nick
}

POKEMON::POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
	int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
	WUXINGTYPE xtype, int xskillcnt, string xnick)
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
	Nick = xnick;
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
	Nick = PET.Get_Nick();
}

POKEMON::~POKEMON()
{
}

void POKEMON::Input_Kind(POKEMONKIND xkind)
{
	Kind = xkind;
}

POKEMONKIND POKEMON::Get_Kind()const
{
	return Kind;
}

void POKEMON::Input_Name(string xname)
{
	Name = xname;
}

string POKEMON::Get_Name()const
{
	return Name;
}

void POKEMON::Input_Rank(int xrank)
{
	Rank = xrank;
}

int POKEMON::Get_Rank()const
{
	return Rank;
}

void POKEMON::Input_Exp(int xexp)
{
	Exp = xexp;
}

int POKEMON::Get_Exp()const
{
	return Exp;
}

void POKEMON::Input_Atk(int xatk)
{
	Atk = xatk;
}

int POKEMON::Get_Atk()const
{
	return Atk;
}

void POKEMON::Input_Def(int xdef)
{
	Def = xdef;
}

int POKEMON::Get_Def()const
{
	return Def;
}

void POKEMON::Input_Hp(int xhp)
{
	Hp = xhp;
}

int POKEMON::Get_Hp()const
{
	return Hp;
}

void POKEMON::Input_AtkI(int xatki)
{
	AtkInterval = xatki;
}

int POKEMON::Get_AtkI()const
{
	return AtkInterval;
}

void POKEMON::Input_Accuracy(double xaccuracy)
{
	Accuracy = xaccuracy;
}

double POKEMON::Get_Accuracy()const
{
	return Accuracy;
}

void POKEMON::Input_Evasiveness(double xevasiveness)
{
	Evasiveness = xevasiveness;
}

double POKEMON::Get_Evasiveness()const
{
	return Evasiveness;
}

void POKEMON::Input_Type(WUXINGTYPE xtype)
{
	wType = xtype;
}

WUXINGTYPE POKEMON::Get_Type()const
{
	return wType;
}

void POKEMON::Input_SkillCnt(int xskillcnt)
{
	SkillCnt = xskillcnt;
}

int POKEMON::Get_SkillCnt()const
{
	return SkillCnt;
}

void POKEMON::Input_Nick(string xnick)
{
	Nick = xnick;
}

string POKEMON::Get_Nick() const
{
	return Nick;
}

void POKEMON::Upgrade()
{
}

void POKEMON::SkillAll()
{
}

//--------------------------------------------------------------------------------------------------------

POWERPET::POWERPET():POKEMON()
{
	Input_Kind(POWER);
}

POWERPET::POWERPET(POKEMONKIND xkind, string xname, int xrank, int xexp,
	int xatk, int xdef, int xhp, int xatki, double xaccuracy,
	double xevasiveness, WUXINGTYPE xtype, int xskillcnt, string xnick)
	:POKEMON(xkind, xname, xrank, xexp, xatk, xdef, xhp, xatki, xaccuracy, xevasiveness, xtype, xskillcnt, xnick)
{
}

POWERPET::POWERPET(const POWERPET & PET):POKEMON(PET)
{
}

//----------------------------------------------------------------------------------------------------------------

TANKPET::TANKPET():POKEMON()
{
	Input_Kind(TANK);
}

TANKPET::TANKPET(POKEMONKIND xkind, string xname, int xrank, int xexp,
	int xatk, int xdef, int xhp, int xatki, double xaccuracy,
	double xevasiveness, WUXINGTYPE xtype, int xskillcnt, string xnick)
	: POKEMON(xkind, xname, xrank, xexp, xatk, xdef, xhp, xatki, xaccuracy, xevasiveness, xtype, xskillcnt, xnick)
{
}

TANKPET::TANKPET(const TANKPET & PET) : POKEMON(PET)
{
}

//----------------------------------------------------------------------------------------------------------------

DEFENSIVEPET::DEFENSIVEPET() :POKEMON()
{
	Input_Kind(DEFENSIVE);
}

DEFENSIVEPET::DEFENSIVEPET(POKEMONKIND xkind, string xname, int xrank, int xexp,
	int xatk, int xdef, int xhp, int xatki, double xaccuracy,
	double xevasiveness, WUXINGTYPE xtype, int xskillcnt, string xnick)
	: POKEMON(xkind, xname, xrank, xexp, xatk, xdef, xhp, xatki, xaccuracy, xevasiveness, xtype, xskillcnt, xnick)
{
}

DEFENSIVEPET::DEFENSIVEPET(const DEFENSIVEPET & PET) : POKEMON(PET)
{
}

//----------------------------------------------------------------------------------------------------------------

AGILEPET::AGILEPET() :POKEMON()
{
	Input_Kind(AGILE);
}

AGILEPET::AGILEPET(POKEMONKIND xkind, string xname, int xrank, int xexp,
	int xatk, int xdef, int xhp, int xatki, double xaccuracy,
	double xevasiveness, WUXINGTYPE xtype, int xskillcnt, string xnick)
	: POKEMON(xkind, xname, xrank, xexp, xatk, xdef, xhp, xatki, xaccuracy, xevasiveness, xtype, xskillcnt, xnick)
{
}

AGILEPET::AGILEPET(const AGILEPET & PET) : POKEMON(PET)
{
}

void SQUIRTLE::Upgrade()
{
}

void SQUIRTLE::SkillAll()
{
}
