#include "pokemon.h"
const int MIN_ATKI = 10;//�趨��͹����������λΪ10^-1s
SKILL::SKILL()
{
}

SKILL::SKILL(string sname, int srank, SKILLKIND skind, int spower, int shit)
{
	SkillName = sname;
	SkillRank = srank;
	SkillKind = skind;
	SkillPower = spower;
	SkillHit = shit;
}

SKILL::SKILL(const SKILL & SK)
{
	SkillName = SK.SkillName;
	SkillRank = SK.SkillRank;
	SkillKind = SK.SkillKind;
	SkillPower = SK.SkillPower;
	SkillHit = SK.SkillHit;
}

//----------------------------------------------------------------------------------------------
//С�������
POKEMON::POKEMON()
{
	//kind��Nameû��Ҫ����ֵ
	Rank = 1;
	Exp = 0;
	// Atk ��ֵ��
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
	WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt)
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
	GotSkillCnt = xskillcnt;
	AllSkillCnt = xallSkillcnt;
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
	AllSkillCnt = PET.Get_ALLSkillCnt();
	GotSkillCnt = PET.Get_GotSkillCnt();
	Nick = PET.Get_Nick();
	for (int i = 0; i < AllSkillCnt; ++i)
	{
		AllSkills[i] = *(PET.Access_AllSkill()+i);
	}
	for (int i = 0; i < GotSkillCnt; ++i)
	{
		GotSkills[i] = PET.Access_GotSkill(i);
	}
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

void POKEMON::Input_GotSkillCnt(int xskillcnt)
{
	GotSkillCnt = xskillcnt;
}

int POKEMON::Get_GotSkillCnt()const
{
	return GotSkillCnt;
}

void POKEMON::Input_ALLSkillCnt(int xskillcnt)
{
	AllSkillCnt = xskillcnt;
}

int POKEMON::Get_ALLSkillCnt() const
{
	return AllSkillCnt;
}

void POKEMON::Input_Nick(string xnick)
{
	Nick = xnick;
}

string POKEMON::Get_Nick() const
{
	return Nick;
}

const SKILL * POKEMON::Access_AllSkill() const
{
	const SKILL *firstSkillPtr = AllSkills;
	return firstSkillPtr;
}

SKILL * POKEMON::Write_AllSkill() 
{
	SKILL *firstSkillPtr = AllSkills;
	return firstSkillPtr;
}

PSKILL POKEMON::Access_GotSkill(int pos) const
{
	return GotSkills[pos];
}

PSKILL * POKEMON::Write_GotSkill(int pos)
{
	return &GotSkills[pos];
}

void POKEMON::RefershRank()
{
	if (Exp >= 0 && Exp < 100)
		Rank = 1;
	else if (Exp >= 100 && Exp < 200)
		Rank = 2;
	else if (Exp >= 200 && Exp < 300)
		Rank = 3;
	else if (Exp >= 300 && Exp < 400)
		Rank = 4;
	else if (Exp >= 400 && Exp < 500)
		Rank = 5;
	else if (Exp >= 500 && Exp < 650)
		Rank = 6;
	else if (Exp >= 650 && Exp < 800)
		Rank = 7;
	else if (Exp >= 800 && Exp < 950)
		Rank = 8;
	else if (Exp >= 950 && Exp < 1100)
		Rank = 9;
	else if (Exp >= 1100 && Exp < 1300)
		Rank = 10;
	else if (Exp >= 1300 && Exp < 1500)
		Rank = 11;
	else if (Exp >= 1500 && Exp < 1700)
		Rank = 12;
	else if (Exp >= 1700 && Exp < 2000)
		Rank = 13;
	else if (Exp >= 2000 && Exp < 2500)
		Rank = 14;
	else if (Exp >= 2500)
		Rank = 15;
}

void POKEMON::PrintPetInfo()
{
	cout << Name << "   Nick:" << Nick << endl;
	cout << "Kind:" << Kind;
	cout << " , Type:" << wType;
	cout << " , Rank:" << Rank;
	cout << " , Exp:" << Exp << endl;
	cout << " , Atk:" << Atk;
	cout << " , Def:" << Def;
	cout << " , Hp:" << Hp;
	cout << " , AtkI:" << AtkInterval << endl;
	cout << " , Accuracy:" << Accuracy;
	cout << " , Evasiveness:" << Evasiveness << endl;
	cout << "ϰ�ü��ܣ�" << endl;
	for (int i = 0; i < GotSkillCnt; ++i)
	{
		cout << GotSkills[i]->SkillName;
		cout << "   ";
	}
	cout << endl;
}

void POKEMON::Upgrade()
{
}

/*void POKEMON::SkillAll()
{
}*/

//--------------------------------------------------------------------------------------------------------

POWERPET::POWERPET():POKEMON()
{
	Input_Kind(POWER);
}

POWERPET::POWERPET(POKEMONKIND xkind, string xname, int xrank, int xexp,
	int xatk, int xdef, int xhp, int xatki, double xaccuracy,
	double xevasiveness, WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt)
	:POKEMON(xkind, xname, xrank, xexp, xatk, xdef, xhp, xatki, xaccuracy, xevasiveness, xtype, xskillcnt, xnick, xallSkillcnt)
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
	double xevasiveness, WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt)
	: POKEMON(xkind, xname, xrank, xexp, xatk, xdef, xhp, xatki, xaccuracy, xevasiveness, xtype, xskillcnt, xnick, xallSkillcnt)
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
	double xevasiveness, WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt)
	: POKEMON(xkind, xname, xrank, xexp, xatk, xdef, xhp, xatki, xaccuracy, xevasiveness, xtype, xskillcnt, xnick, xallSkillcnt)
{
}

DEFENSIVEPET::DEFENSIVEPET(const DEFENSIVEPET & PET) : POKEMON(PET)
{
}

AGILEPET::AGILEPET() :POKEMON()
{
	Input_Kind(AGILE);
}

AGILEPET::AGILEPET(POKEMONKIND xkind, string xname, int xrank, int xexp,
	int xatk, int xdef, int xhp, int xatki, double xaccuracy,
	double xevasiveness, WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt)
	: POKEMON(xkind, xname, xrank, xexp, xatk, xdef, xhp, xatki, xaccuracy, xevasiveness, xtype, xskillcnt, xnick, xallSkillcnt)
{
}

AGILEPET::AGILEPET(const AGILEPET & PET) : POKEMON(PET)
{
}

//----------------------------------------------------------------------------------------------------------------
//������Magikarp��1-5��->������Gyarados��6-10��->����������Super Gyarados��11-15��,�߹���
GYARADOS::GYARADOS() : POWERPET()
{
	Input_Name("������Magikarp");//������
	Input_Rank(1);
	Input_Exp(0);////////////����ֵ��ʼΪ0
	Input_Hp(95);
	//Input_AtkI(81);
	Input_AtkI(40);
	Input_Atk(125);
	Input_Def(79);
	Input_Accuracy(1);
	Input_Evasiveness(0.2);
	Input_Type(SHUI);
	Input_GotSkillCnt(0);
	SkillAll();//�������м���
	//������ʼ���ܣ�Ĭ��ָ�ɵ�0������Ϊ��ʼ����
	PSKILL* newSkill = Write_GotSkill(0);
	*newSkill = Write_AllSkill();
	(*newSkill)->Selected = OWNED;	
	Input_GotSkillCnt(1);
}

GYARADOS::GYARADOS(const GYARADOS & PET) : POWERPET(PET)
{
	//SkillAll();//�������м���
}

void GYARADOS::Upgrade()
{
	string currentName = Get_Name();
	srand((unsigned)time(NULL));
	int currentRank = Get_Rank();
	cout << currentName << "����" << currentRank << "����" << endl;
	if (currentRank >= 6)
	{
		Input_Name("������Gyarados");
		cout << "����Ϊ" << "������Gyarados !" << endl;
	}
	else if (currentRank >= 11)
	{
		Input_Name("����������Super Gyarados");
		cout << "����Ϊ" << "����������Super Gyarados !" << endl;
	}
	int currentHp = Get_Hp();
	int currentAtkI = Get_AtkI();
	int currentAtk = Get_Atk();
	int currentDef = Get_Def();
	int addition = rand() % 5 + 1;
	currentHp += addition;
	cout << "HP+" << addition;
	Input_Hp(currentHp);
	addition = rand() % 5 + 1;
	if (currentAtkI - addition > MIN_ATKI)
	{
		currentAtkI -= addition;
		cout << " , ATKI-" << addition;
	}
	else
	{
		cout << " , ATKI-" << currentAtkI - MIN_ATKI << "(�������ޣ�";
		currentAtkI = MIN_ATKI;		
	}
	Input_AtkI(currentAtkI);
	addition = rand() % 5 + 6;
	cout << " , ATK+" << addition;
	currentAtk += addition;
	Input_Atk(currentAtk);
	addition = rand() % 5 + 1;
	cout << " , DEF+" << addition << endl;
	currentDef += addition;
	Input_Def(currentDef);

	//�м��ʻ�ü���
	int learnSkill = rand() % 10;
	if (learnSkill >= 5 && Get_GotSkillCnt() < Get_ALLSkillCnt())//ѧ���¼���
	{
		learnSkill = rand() % Get_ALLSkillCnt();
		while ((Access_AllSkill() + learnSkill)->Selected == OWNED)
		{
			learnSkill = rand() % Get_ALLSkillCnt();
		}
		int learnSkillCnt = Get_GotSkillCnt();
		PSKILL* newSkill = Write_GotSkill(learnSkillCnt);
		*newSkill = Write_AllSkill() + learnSkill;
		(*newSkill)->Selected = OWNED;
		++learnSkillCnt;
		Input_GotSkillCnt(learnSkillCnt);
		cout << "����¼��ܣ�" << (*newSkill)->SkillName << endl;
	}
}

void GYARADOS::SkillAll()
{
	int therank;
	int AllSkillCnt = 0;
	SKILL *theSkillPtr = Write_AllSkill();
	//��0�����ܣ�����磬�����ͼ���
	theSkillPtr->SkillName = "�����Twister";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 40;
	theSkillPtr->SkillHit = 100;
	//��1�����ܣ���֮�裬������������
	++theSkillPtr;
	theSkillPtr->SkillName = "��֮��Dragon Dance";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = SELFDEFFENCE;
	theSkillPtr->SkillPower = 20;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��2�����ܣ����꣬�ָ���������ֵ
	theSkillPtr->SkillName = "����Rain Dance";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = REHP;
	theSkillPtr->SkillPower = 20;
	theSkillPtr->SkillHit = 50;
	++AllSkillCnt;
	//��0�����ܣ���֮ŭ�������ͼ���
	theSkillPtr->SkillName = "��֮ŭDragon Rage";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 120;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��4�����ܣ����ۣ����Ͷ��ַ�����
	theSkillPtr->SkillName = "����Leer";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = OPPDEFEENCE;
	theSkillPtr->SkillPower = 20;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��5�����ܣ�ˮ�ڣ������ͼ���
	theSkillPtr->SkillName = "ˮ��Hydro Pump";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 110;
	theSkillPtr->SkillHit = 80;
	++AllSkillCnt;
	Input_ALLSkillCnt(AllSkillCnt);
}

//С����Happiny->������Chansey->�Ҹ���Blissey,�����
HAPPINY::HAPPINY() : TANKPET()
{
	Input_Name("С����Happiny");
	Input_Rank(1);
	Input_Exp(0);////////////����ֵ��ʼΪ0
	Input_Hp(255);
	//Input_AtkI(55);
	Input_AtkI(60);
	Input_Atk(10);
	Input_Def(10);
	Input_Accuracy(1);
	Input_Evasiveness(0.1);
	Input_Type(TU);
	Input_GotSkillCnt(0);
	SkillAll();//�������м���
	//������ʼ���ܣ�Ĭ��ָ�ɵ�0������Ϊ��ʼ����
	PSKILL* newSkill = Write_GotSkill(0);
	*newSkill = Write_AllSkill();
	(*newSkill)->Selected = OWNED;
	Input_GotSkillCnt(1);
}

HAPPINY::HAPPINY(const HAPPINY & PET) : TANKPET(PET)
{
	//SkillAll();//�������м���
}

void HAPPINY::Upgrade()
{
	string currentName = Get_Name();
	srand((unsigned)time(NULL));
	int currentRank = Get_Rank();
	cout << currentName << "����" << currentRank << "����" << endl;
	if (currentRank >= 6)
	{
		Input_Name("������Chansey");
		cout << "����Ϊ" << "������Chansey !" << endl;
	}
	else if (currentRank >= 11)
	{
		Input_Name("�Ҹ���Blissey");
		cout << "����Ϊ" << "�Ҹ���Blissey !" << endl;
	}
	int currentHp = Get_Hp();
	int currentAtkI = Get_AtkI();
	int currentAtk = Get_Atk();
	int currentDef = Get_Def();
	int addition = rand() % 5 + 6;
	currentHp += addition;
	cout << "HP+" << addition;
	Input_Hp(currentHp);
	addition = rand() % 5 + 1;
	if (currentAtkI - addition > MIN_ATKI)
	{
		currentAtkI -= addition;
		cout << " , ATKI-" << addition;
	}
	else
	{
		cout << " , ATKI-" << currentAtkI - MIN_ATKI << "(�������ޣ�";
		currentAtkI = MIN_ATKI;
	}
	Input_AtkI(currentAtkI);
	addition = rand() % 5 + 1;
	cout << " , ATK+" << addition;
	currentAtk += addition;
	Input_Atk(currentAtk);
	addition = rand() % 5 + 1;
	cout << " , DEF+" << addition << endl;
	currentDef += addition;
	Input_Def(currentDef);

	//�м��ʻ�ü���
	int learnSkill = rand() % 10;
	if (learnSkill >= 5 && Get_GotSkillCnt() < Get_ALLSkillCnt())//ѧ���¼���
	{
		learnSkill = rand() % Get_ALLSkillCnt();
		while ((Access_AllSkill() + learnSkill)->Selected == OWNED)
		{
			learnSkill = rand() % Get_ALLSkillCnt();
		}
		int learnSkillCnt = Get_GotSkillCnt();
		PSKILL* newSkill = Write_GotSkill(learnSkillCnt);
		*newSkill = Write_AllSkill() + learnSkill;
		(*newSkill)->Selected = OWNED;
		++learnSkillCnt;
		Input_GotSkillCnt(learnSkillCnt);
		cout << "����¼��ܣ�" << (*newSkill)->SkillName << endl;
	}
}

void HAPPINY::SkillAll()
{
	int therank;
	int AllSkillCnt = 0;
	SKILL *theSkillPtr = Write_AllSkill();
	//��0�����ܣ�ը���������ͼ���
	theSkillPtr->SkillName = "ը��Egg Bomb";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 100;
	theSkillPtr->SkillHit = 90;
	++AllSkillCnt;
	//��1�����ܣ���Բ������Լ��ķ�����
	++theSkillPtr;
	theSkillPtr->SkillName = "��ԲDefense Curl";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = SELFDEFFENCE;
	theSkillPtr->SkillPower = 10;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��2�����ܣ��������ָ���������ֵ
	theSkillPtr->SkillName = "����Soft-Boiled";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = REHP;
	theSkillPtr->SkillPower = 100;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��3�����ܣ���ײ�������ͼ���
	theSkillPtr->SkillName = "��ײTake Down";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 90;
	theSkillPtr->SkillHit = 85;
	++AllSkillCnt;
	//��4�����ܣ���ʹ֮�ǣ����Ͷ��ַ�����
	theSkillPtr->SkillName = "��ʹ֮��Sweet Kiss";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = OPPDEFEENCE;
	theSkillPtr->SkillPower = 20;
	theSkillPtr->SkillHit = 80;
	++AllSkillCnt;
	//��5�����ܣ��������ƣ������ͼ���
	theSkillPtr->SkillName = "��������Double Slap";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 15;
	theSkillPtr->SkillHit = 85;
	++AllSkillCnt;
	Input_ALLSkillCnt(AllSkillCnt);
}

//�����Squirtle(1-5����->�����Wartortle(6-10����->ˮ����Blastoise(11-15�������߷���
SQUIRTLE::SQUIRTLE():DEFENSIVEPET()
{
	Input_Name("�����Squirtle");
	Input_Rank(1);
	Input_Exp(0);////////////����ֵ��ʼΪ0
	Input_Hp(79);
	//Input_AtkI(78);
	Input_AtkI(45);
	Input_Atk(83);
	Input_Def(100);
	Input_Accuracy(1);
	Input_Evasiveness(0.2);
	Input_Type(SHUI);
	Input_GotSkillCnt(0);
	SkillAll();//�������м���
	//������ʼ���ܣ�Ĭ��ָ�ɵ�0������Ϊ��ʼ����
	PSKILL* newSkill = Write_GotSkill(0);
	*newSkill = Write_AllSkill();
	(*newSkill)->Selected = OWNED;
	Input_GotSkillCnt(1);
}

SQUIRTLE::SQUIRTLE(const SQUIRTLE & PET) : DEFENSIVEPET(PET)
{
	//SkillAll();//�������м���
}

void SQUIRTLE::Upgrade()
{
	string currentName = Get_Name();
	srand((unsigned)time(NULL));
	int currentRank = Get_Rank();
	cout << currentName << "����" << currentRank << "����" << endl;
	if (currentRank >= 6)
	{
		Input_Name("�����Wartortle");
		cout << "����Ϊ" << "�����Wartortle !" << endl;
	}
	else if (currentRank >= 11)
	{
		Input_Name("ˮ����Blastoise");
		cout << "����Ϊ" << "ˮ����Blastoise !" << endl;
	}
	int currentHp = Get_Hp();
	int currentAtkI = Get_AtkI();
	int currentAtk = Get_Atk();
	int currentDef = Get_Def();
	int addition = rand() % 5 + 1;
	currentHp += addition;
	cout << "HP+" << addition;
	Input_Hp(currentHp);
	addition = rand() % 5 + 1;
	if (currentAtkI - addition > MIN_ATKI)
	{
		currentAtkI -= addition;
		cout << " , ATKI-" << addition;
	}
	else
	{
		cout << " , ATKI-" << currentAtkI - MIN_ATKI << "(�������ޣ�";
		currentAtkI = MIN_ATKI;
	}
	Input_AtkI(currentAtkI);
	addition = rand() % 5 + 1;
	cout << " , ATK+" << addition;
	currentAtk += addition;
	Input_Atk(currentAtk);
	addition = rand() % 5 + 6;
	cout << " , DEF+" << addition << endl;
	currentDef += addition;
	Input_Def(currentDef);

	//�м��ʻ�ü���
	int learnSkill = rand() % 10;
	if (learnSkill >= 5 && Get_GotSkillCnt() < Get_ALLSkillCnt())//ѧ���¼���
	{
		learnSkill = rand() % Get_ALLSkillCnt();
		while ((Access_AllSkill() + learnSkill)->Selected == OWNED)
		{
			learnSkill = rand() % Get_ALLSkillCnt();
		}
		int learnSkillCnt = Get_GotSkillCnt();
		PSKILL* newSkill = Write_GotSkill(learnSkillCnt);
		*newSkill = Write_AllSkill() + learnSkill;
		(*newSkill)->Selected = OWNED;
		++learnSkillCnt;
		Input_GotSkillCnt(learnSkillCnt);
		cout << "����¼��ܣ�" << (*newSkill)->SkillName << endl;
	}
}

void SQUIRTLE::SkillAll()
{
	int therank;
	int AllSkillCnt = 0;
	SKILL *theSkillPtr= Write_AllSkill();
	//��0�����ܣ�������ת�������ͼ���
	theSkillPtr->SkillName = "������תRapid Spin";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 20;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��1�����ܣ�������У�����Լ��ķ�����
	++theSkillPtr;
	theSkillPtr->SkillName = "�������Withdraw";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = SELFDEFFENCE;
	theSkillPtr->SkillPower = 20;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��2�����ܣ�˯�����ָ���������ֵ
	theSkillPtr->SkillName = "˯��Rest";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = REHP;
	theSkillPtr->SkillPower = 30;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��3�����ܣ�̩ɽѹ���������ͼ���
	theSkillPtr->SkillName = "̩ɽѹ��Body Slam";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 90;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��4�����ܣ��������������Ͷ��ַ�����
	theSkillPtr->SkillName = "��������Ice Beam";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = OPPDEFEENCE;
	theSkillPtr->SkillPower = 30;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��5�����ܣ������������ͼ���(��������������
	theSkillPtr->SkillName = "����Snore";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 60;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	Input_ALLSkillCnt(AllSkillCnt);
}

//����xMewtwoX->����Mewtwo->��������yMewtwoY��������
MEWTWO::MEWTWO() : AGILEPET()
{
	Input_Name("����x MewtwoX");
	Input_Rank(1);
	Input_Exp(0);////////////����ֵ��ʼΪ0
	Input_Hp(106);
	//Input_AtkI(130);
	Input_AtkI(20);
	Input_Atk(110);
	Input_Def(90);
	Input_Accuracy(1);
	Input_Evasiveness(0.4);
	Input_Type(TU);
	Input_GotSkillCnt(0);
	SkillAll();//�������м���
	//������ʼ���ܣ�Ĭ��ָ�ɵ�0������Ϊ��ʼ����
	PSKILL* newSkill = Write_GotSkill(0);
	*newSkill = Write_AllSkill();
	(*newSkill)->Selected = OWNED;
	Input_GotSkillCnt(1);
}

MEWTWO::MEWTWO(const MEWTWO & PET) : AGILEPET(PET)
{
	//Input_GotSkillCnt(1);
}

void MEWTWO::Upgrade()
{
	string currentName = Get_Name();
	srand((unsigned)time(NULL));
	int currentRank = Get_Rank();
	cout << currentName << "����" << currentRank << "����" << endl;
	if (currentRank >= 6)
	{
		Input_Name("����Mewtwo");
		cout << "����Ϊ" << "����Mewtwo !" << endl;
	}
	else if (currentRank >= 11)
	{
		Input_Name("��������y MewtwoY");
		cout << "����Ϊ" << "��������y MewtwoY !" << endl;
	}
	int currentHp = Get_Hp();
	int currentAtkI = Get_AtkI();
	int currentAtk = Get_Atk();
	int currentDef = Get_Def();
	int addition = rand() % 5 + 1;
	currentHp += addition;
	cout << "HP+" << addition;
	Input_Hp(currentHp);
	addition = rand() % 2 + 3;
	if (currentAtkI - addition > MIN_ATKI)
	{
		currentAtkI -= addition;
		cout << " , ATKI-" << addition;
	}
	else
	{
		cout << " , ATKI-" << currentAtkI - MIN_ATKI << "(�������ޣ�";
		currentAtkI = MIN_ATKI;
	}
	Input_AtkI(currentAtkI);
	addition = rand() % 5 + 1;
	cout << " , ATK+" << addition;
	currentAtk += addition;
	Input_Atk(currentAtk);
	addition = rand() % 5 + 1;
	cout << " , DEF+" << addition << endl;
	currentDef += addition;
	Input_Def(currentDef);

	//�м��ʻ�ü���
	int learnSkill = rand() % 10;
	if (learnSkill >= 5 && Get_GotSkillCnt() < Get_ALLSkillCnt())//ѧ���¼���
	{
		learnSkill = rand() % Get_ALLSkillCnt();
		while ((Access_AllSkill() + learnSkill)->Selected == OWNED)
		{
			learnSkill = rand() % Get_ALLSkillCnt();
		}
		int learnSkillCnt = Get_GotSkillCnt();
		PSKILL* newSkill = Write_GotSkill(learnSkillCnt);
		*newSkill = Write_AllSkill() + learnSkill;
		(*newSkill)->Selected = OWNED;
		++learnSkillCnt;
		Input_GotSkillCnt(learnSkillCnt);
		cout << "����¼��ܣ�" << (*newSkill)->SkillName << endl;
	}
}

void MEWTWO::SkillAll()
{
	int therank;
	int AllSkillCnt = 0;
	SKILL *theSkillPtr = Write_AllSkill();
	//��0�����ܣ��������У������ͼ���
	theSkillPtr->SkillName = "��������Psycho Cut";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 20;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��1�����ܣ����ϣ�����Լ��ķ�����
	++theSkillPtr;
	theSkillPtr->SkillName = "����Barrier";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = SELFDEFFENCE;
	theSkillPtr->SkillPower = 50;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��2�����ܣ������������ָ���������ֵ
	theSkillPtr->SkillName = "��������Recover";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = REHP;
	theSkillPtr->SkillPower = 60;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��3�����ܣ�����ǿ������ͼ���
	theSkillPtr->SkillName = "����ǿ��Psychic";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 90;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��4�����ܣ��������Ͷ��ַ�����
	theSkillPtr->SkillName = "����";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = OPPDEFEENCE;
	theSkillPtr->SkillPower = 40;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��5�����ܣ�������ƣ������ͼ���
	theSkillPtr->SkillName = "�������Psystrike";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 100;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	Input_ALLSkillCnt(AllSkillCnt);
}

//�����Litten->������Torracat->������Х��Incineroar��������
INCINEROAR::INCINEROAR() : POWERPET()
{
	Input_Name("�����Litten");
	Input_Rank(1);
	Input_Exp(0);////////////����ֵ��ʼΪ0
	Input_Hp(95);
	//Input_AtkI(60);
	Input_AtkI(50);
	Input_Atk(115);
	Input_Def(90);
	Input_Accuracy(1);
	Input_Evasiveness(0.2);
	Input_Type(HUO);
	Input_GotSkillCnt(0);
	SkillAll();//�������м���
	//������ʼ���ܣ�Ĭ��ָ�ɵ�0������Ϊ��ʼ����
	PSKILL* newSkill = Write_GotSkill(0);
	*newSkill = Write_AllSkill();
	(*newSkill)->Selected = OWNED;
	Input_GotSkillCnt(1);
}

INCINEROAR::INCINEROAR(const INCINEROAR & PET) : POWERPET(PET)
{
	//SkillAll();//�������м���
}

void INCINEROAR::Upgrade()
{
	string currentName = Get_Name();
	srand((unsigned)time(NULL));
	int currentRank = Get_Rank();
	cout << currentName << "����" << currentRank << "����" << endl;
	if (currentRank >= 6)
	{
		Input_Name("������Torracat");
		cout << "����Ϊ" << "������Torracat !" << endl;
	}
	else if (currentRank >= 11)
	{
		Input_Name("������Х��Incineroar");
		cout << "����Ϊ" << "������Х��Incineroar !" << endl;
	}
	int currentHp = Get_Hp();
	int currentAtkI = Get_AtkI();
	int currentAtk = Get_Atk();
	int currentDef = Get_Def();
	int addition = rand() % 5 + 1;
	currentHp += addition;
	cout << "HP+" << addition;
	Input_Hp(currentHp);
	addition = rand() % 5 + 1;
	if (currentAtkI - addition > MIN_ATKI)
	{
		currentAtkI -= addition;
		cout << " , ATKI-" << addition;
	}
	else
	{
		cout << " , ATKI-" << currentAtkI - MIN_ATKI << "(�������ޣ�";
		currentAtkI = MIN_ATKI;
	}
	Input_AtkI(currentAtkI);
	addition = rand() % 5 + 6;
	cout << " , ATK+" << addition;
	currentAtk += addition;
	Input_Atk(currentAtk);
	addition = rand() % 5 + 1;
	cout << " , DEF+" << addition << endl;
	currentDef += addition;
	Input_Def(currentDef);

	//�м��ʻ�ü���
	int learnSkill = rand() % 10;
	if (learnSkill >= 5 && Get_GotSkillCnt() < Get_ALLSkillCnt())//ѧ���¼���
	{
		learnSkill = rand() % Get_ALLSkillCnt();
		while ((Access_AllSkill() + learnSkill)->Selected == OWNED)
		{
			learnSkill = rand() % Get_ALLSkillCnt();
		}
		int learnSkillCnt = Get_GotSkillCnt();
		PSKILL* newSkill = Write_GotSkill(learnSkillCnt);
		*newSkill = Write_AllSkill() + learnSkill;
		(*newSkill)->Selected = OWNED;
		++learnSkillCnt;
		Input_GotSkillCnt(learnSkillCnt);
		cout << "����¼��ܣ�" << (*newSkill)->SkillName << endl;
	}
}

void INCINEROAR::SkillAll()
{
	int therank;
	int AllSkillCnt = 0;
	SKILL *theSkillPtr = Write_AllSkill();
	//��0�����ܣ�������棬�����ͼ���
	theSkillPtr->SkillName = "�������Flamethrower";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 90;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��1�����ܣ�����������Լ��ķ�����
	++theSkillPtr;
	theSkillPtr->SkillName = "����Bulk Up";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = SELFDEFFENCE;
	theSkillPtr->SkillPower = 40;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��2�����ܣ��𻨣������ͼ���
	theSkillPtr->SkillName = "��Ember";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = REHP;
	theSkillPtr->SkillPower = 40;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��3�����ܣ�DD�𹴱ۣ������ͼ���
	theSkillPtr->SkillName = "DD�𹴱�Darkest Lariat";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 85;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��4�����ܣ����򣬽��Ͷ��ַ�����
	theSkillPtr->SkillName = "����Lick";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = OPPDEFEENCE;
	theSkillPtr->SkillPower = 30;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��5�����ܣ������棬�����ͼ���
	theSkillPtr->SkillName = "������Flare Blitz";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 120;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	Input_ALLSkillCnt(AllSkillCnt);
}

//С��ȻWynaut->��Ȼ��Wobbuffet�������
WOBBUFFET::WOBBUFFET() : TANKPET()
{
	Input_Name("С��ȻWynaut");
	Input_Rank(1);
	Input_Exp(0);////////////����ֵ��ʼΪ0
	Input_Hp(190);
	//Input_AtkI(33);
	Input_AtkI(90);
	Input_Atk(33);
	Input_Def(58);
	Input_Accuracy(1);
	Input_Evasiveness(0.1);
	Input_Type(MU);
	Input_GotSkillCnt(0);
	SkillAll();//�������м���
	//������ʼ���ܣ�Ĭ��ָ�ɵ�0������Ϊ��ʼ����
	PSKILL* newSkill = Write_GotSkill(0);
	*newSkill = Write_AllSkill();
	(*newSkill)->Selected = OWNED;
	Input_GotSkillCnt(1);
}

WOBBUFFET::WOBBUFFET(const WOBBUFFET & PET) : TANKPET(PET)
{
	//SkillAll();//�������м���
}

void WOBBUFFET::Upgrade()
{
	string currentName = Get_Name();
	srand((unsigned)time(NULL));
	int currentRank = Get_Rank();
	cout << currentName << "����" << currentRank << "����" << endl;
	if (currentRank >= 8)
	{
		Input_Name("��Ȼ��Wobbuffet");
		cout << "����Ϊ" << "��Ȼ��Wobbuffet !" << endl;
	}
	int currentHp = Get_Hp();
	int currentAtkI = Get_AtkI();
	int currentAtk = Get_Atk();
	int currentDef = Get_Def();
	int addition = rand() % 5 + 1;
	currentHp += addition;
	cout << "HP+" << addition;
	Input_Hp(currentHp);
	addition = rand() % 5 + 6;
	if (currentAtkI - addition > MIN_ATKI)
	{
		currentAtkI -= addition;
		cout << " , ATKI-" << addition;
	}
	else
	{
		cout << " , ATKI-" << currentAtkI - MIN_ATKI << "(�������ޣ�";
		currentAtkI = MIN_ATKI;
	}
	Input_AtkI(currentAtkI);
	addition = rand() % 5 + 1;
	cout << " , ATK+" << addition;
	currentAtk += addition;
	Input_Atk(currentAtk);
	addition = rand() % 5 + 1;
	cout << " , DEF+" << addition << endl;
	currentDef += addition;
	Input_Def(currentDef);

	//�м��ʻ�ü���
	int learnSkill = rand() % 10;
	if (learnSkill >= 5 && Get_GotSkillCnt() < Get_ALLSkillCnt())//ѧ���¼���
	{
		learnSkill = rand() % Get_ALLSkillCnt();
		while ((Access_AllSkill() + learnSkill)->Selected == OWNED)
		{
			learnSkill = rand() % Get_ALLSkillCnt();
		}
		int learnSkillCnt = Get_GotSkillCnt();
		PSKILL* newSkill = Write_GotSkill(learnSkillCnt);
		*newSkill = Write_AllSkill() + learnSkill;
		(*newSkill)->Selected = OWNED;
		++learnSkillCnt;
		Input_GotSkillCnt(learnSkillCnt);
		cout << "����¼��ܣ�" << (*newSkill)->SkillName << endl;
	}
}

void WOBBUFFET::SkillAll()
{
	int therank;
	int AllSkillCnt = 0;
	SKILL *theSkillPtr = Write_AllSkill();
	//��0�����ܣ�Ծ�𣬹����ͼ���
	theSkillPtr->SkillName = "Ծ��Splash";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 20;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��1�����ܣ������ػ�������Լ��ķ�����
	++theSkillPtr;
	theSkillPtr->SkillName = "�����ػ�Safeguard";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = SELFDEFFENCE;
	theSkillPtr->SkillPower = 40;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��2�����ܣ���Ӯ���ָ�����HP
	theSkillPtr->SkillName = "��ӮLie Win";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = REHP;
	theSkillPtr->SkillPower = 80;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��3�����ܣ����淴�䣬�����ͼ���
	theSkillPtr->SkillName = "���淴��Mirror Coat";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 30;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��4�����ܣ����������Ͷ��ַ�����
	theSkillPtr->SkillName = "����Charm";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = OPPDEFEENCE;
	theSkillPtr->SkillPower = 30;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��5�����ܣ�ץ�񣬹����ͼ���
	theSkillPtr->SkillName = "ץ��Crazy";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 60;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	Input_ALLSkillCnt(AllSkillCnt);
}

//������Onix->�����Steelix->��������ߣ�������
STEELIX::STEELIX() : DEFENSIVEPET()
{
	Input_Name("������Onix");
	Input_Rank(1);
	Input_Exp(0);////////////����ֵ��ʼΪ0
	Input_Hp(75);
	//Input_AtkI(30);
	Input_AtkI(100);
	Input_Atk(85);
	Input_Def(200);
	Input_Accuracy(1);
	Input_Evasiveness(0.2);
	Input_Type(TU);
	Input_GotSkillCnt(0);
	SkillAll();//�������м���
	//������ʼ���ܣ�Ĭ��ָ�ɵ�0������Ϊ��ʼ����
	PSKILL* newSkill = Write_GotSkill(0);
	*newSkill = Write_AllSkill();
	(*newSkill)->Selected = OWNED;
	Input_GotSkillCnt(1);
}

STEELIX::STEELIX(const STEELIX & PET) : DEFENSIVEPET(PET)
{
	//SkillAll();//�������м���
}

void STEELIX::Upgrade()
{
	string currentName = Get_Name();
	srand((unsigned)time(NULL));
	int currentRank = Get_Rank();
	cout << currentName << "����" << currentRank << "����" << endl;
	if (currentRank >= 6)
	{
		Input_Name("�����Steelix");
		cout << "����Ϊ" << "�����Steelix !" << endl;
	}
	else if (currentRank >= 11)
	{
		Input_Name("���������Super Steelix");
		cout << "����Ϊ" << "���������Super Steelix !" << endl;
	}
	int currentHp = Get_Hp();
	int currentAtkI = Get_AtkI();
	int currentAtk = Get_Atk();
	int currentDef = Get_Def();
	int addition = rand() % 5 + 1;
	currentHp += addition;
	cout << "HP+" << addition;
	Input_Hp(currentHp);
	addition = rand() % 5 + 1;
	if (currentAtkI - addition > MIN_ATKI)
	{
		currentAtkI -= addition;
		cout << " , ATKI-" << addition;
	}
	else
	{
		cout << " , ATKI-" << currentAtkI - MIN_ATKI << "(�������ޣ�";
		currentAtkI = MIN_ATKI;
	}
	Input_AtkI(currentAtkI);
	addition = rand() % 5 + 1;
	cout << " , ATK+" << addition;
	currentAtk += addition;
	Input_Atk(currentAtk);
	addition = rand() % 5 + 6;
	cout << " , DEF+" << addition << endl;
	currentDef += addition;
	Input_Def(currentDef);

	//�м��ʻ�ü���
	int learnSkill = rand() % 10;
	if (learnSkill >= 5 && Get_GotSkillCnt() < Get_ALLSkillCnt())//ѧ���¼���
	{
		learnSkill = rand() % Get_ALLSkillCnt();
		while ((Access_AllSkill() + learnSkill)->Selected == OWNED)
		{
			learnSkill = rand() % Get_ALLSkillCnt();
		}
		int learnSkillCnt = Get_GotSkillCnt();
		PSKILL* newSkill = Write_GotSkill(learnSkillCnt);
		*newSkill = Write_AllSkill() + learnSkill;
		(*newSkill)->Selected = OWNED;
		++learnSkillCnt;
		Input_GotSkillCnt(learnSkillCnt);
		cout << "����¼��ܣ�" << (*newSkill)->SkillName << endl;
	}
}

void STEELIX::SkillAll()
{
	int therank;
	int AllSkillCnt = 0;
	SKILL *theSkillPtr = Write_AllSkill();
	//��0�����ܣ�����������ͼ���
	theSkillPtr->SkillName = "���Bind";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 35;
	theSkillPtr->SkillHit = 85;
	++AllSkillCnt;
	//��1�����ܣ���Ӳ������Լ��ķ�����
	++theSkillPtr;
	theSkillPtr->SkillName = "��ӲHarden";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = SELFDEFFENCE;
	theSkillPtr->SkillPower = 60;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��2�����ܣ�����ͣ��ָ�����HP
	theSkillPtr->SkillName = "�����Mud Sport";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = REHP;
	theSkillPtr->SkillPower = 40;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��3�����ܣ���ʯ�������ͼ���
	theSkillPtr->SkillName = "��ʯRock Throw";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 50;
	theSkillPtr->SkillHit = 90;
	++AllSkillCnt;
	//��4�����ܣ����䣬���Ͷ��ַ�����
	theSkillPtr->SkillName = "����Curse";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = OPPDEFEENCE;
	theSkillPtr->SkillPower = 30;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��5�����ܣ���β�������ͼ���
	theSkillPtr->SkillName = "��βIron Tail";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 100;
	theSkillPtr->SkillHit = 75;
	++AllSkillCnt;
	Input_ALLSkillCnt(AllSkillCnt);
}

//����Abra->�»���Kadabra->����Alakazam��������
ALAKAZAM::ALAKAZAM() : AGILEPET()
{
	Input_Name("����Abra");
	Input_Rank(1);
	Input_Exp(0);////////////����ֵ��ʼΪ0
	Input_Hp(55);
	//Input_AtkI(120);
	Input_AtkI(25);
	Input_Atk(50);
	Input_Def(45);
	Input_Accuracy(1);
	Input_Evasiveness(0.4);
	Input_Type(JIN);
	Input_GotSkillCnt(0);
	SkillAll();//�������м���
	//������ʼ���ܣ�Ĭ��ָ�ɵ�0������Ϊ��ʼ����
	PSKILL* newSkill = Write_GotSkill(0);
	*newSkill = Write_AllSkill();
	(*newSkill)->Selected = OWNED;
	Input_GotSkillCnt(1);
}

ALAKAZAM::ALAKAZAM(const ALAKAZAM & PET) : AGILEPET(PET)
{
	//SkillAll();//�������м���
}

void ALAKAZAM::Upgrade()
{
	string currentName = Get_Name();
	srand((unsigned)time(NULL));
	int currentRank = Get_Rank();
	cout << currentName << "����" << currentRank << "����" << endl;
	if (currentRank >= 6)
	{
		Input_Name("�»���Kadabra");
		cout << "����Ϊ" << "�»���Kadabra !" << endl;
	}
	else if (currentRank >= 11)
	{
		Input_Name("����Alakazam");
		cout << "����Ϊ" << "����Alakazam !" << endl;
	}
	int currentHp = Get_Hp();
	int currentAtkI = Get_AtkI();
	int currentAtk = Get_Atk();
	int currentDef = Get_Def();
	int addition = rand() % 5 + 1;
	currentHp += addition;
	cout << "HP+" << addition;
	Input_Hp(currentHp);
	addition = rand() % 2 + 3;
	if (currentAtkI - addition > MIN_ATKI)
	{
		currentAtkI -= addition;
		cout << " , ATKI-" << addition;
	}
	else
	{
		cout << " , ATKI-" << currentAtkI - MIN_ATKI << "(�������ޣ�";
		currentAtkI = MIN_ATKI;
	}
	Input_AtkI(currentAtkI);
	addition = rand() % 5 + 1;
	cout << " , ATK+" << addition;
	currentAtk += addition;
	Input_Atk(currentAtk);
	addition = rand() % 5 + 1;
	cout << " , DEF+" << addition << endl;
	currentDef += addition;
	Input_Def(currentDef);

	//�м��ʻ�ü���
	int learnSkill = rand() % 10;
	if (learnSkill >= 5 && Get_GotSkillCnt() < Get_ALLSkillCnt())//ѧ���¼���
	{
		learnSkill = rand() % Get_ALLSkillCnt();
		while ((Access_AllSkill() + learnSkill)->Selected == OWNED)
		{
			learnSkill = rand() % Get_ALLSkillCnt();
		}
		int learnSkillCnt = Get_GotSkillCnt();
		PSKILL* newSkill = Write_GotSkill(learnSkillCnt);
		*newSkill = Write_AllSkill() + learnSkill;
		(*newSkill)->Selected = OWNED;
		++learnSkillCnt;
		Input_GotSkillCnt(learnSkillCnt);
		cout << "����¼��ܣ�" << (*newSkill)->SkillName << endl;
	}
}

void ALAKAZAM::SkillAll()
{
	int therank;
	int AllSkillCnt = 0;
	SKILL *theSkillPtr = Write_AllSkill();
	//��0�����ܣ�������ߣ������ͼ���
	theSkillPtr->SkillName = "�������Psybeam";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 65;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��1�����ܣ�����ڣ�����Լ��ķ�����
	++theSkillPtr;
	theSkillPtr->SkillName = "�����Reflect";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = SELFDEFFENCE;
	theSkillPtr->SkillPower = 30;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��2�����ܣ������������ָ�����HP
	theSkillPtr->SkillName = "��������Recover";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = REHP;
	theSkillPtr->SkillPower = 50;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��3�����ܣ��������У������ͼ���
	theSkillPtr->SkillName = "��������Psycho Cut";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 80;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��4�����ܣ����������Ͷ��ַ�����
	theSkillPtr->SkillName = "����Disable";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = OPPDEFEENCE;
	theSkillPtr->SkillPower = 40;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	//��5�����ܣ�Ԥ֪δ���������ͼ���
	theSkillPtr->SkillName = "Ԥ֪δ��Future Sight";
	theSkillPtr->SkillRank = 1;
	theSkillPtr->SkillKind = ATTACK;
	theSkillPtr->SkillPower = 100;
	theSkillPtr->SkillHit = 100;
	++AllSkillCnt;
	Input_ALLSkillCnt(AllSkillCnt);
}
