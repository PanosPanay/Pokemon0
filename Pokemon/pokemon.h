#include<iostream>
#include<string.h>
#include<windows.h>
#include<time.h>
using namespace std;
const int SKILL_NUM = 20;//�趨һ���������ӵ�еļ���������Ϊ20
const int MIN_ATKI = 10;//�趨��͹����������λΪ10^-1s

//POWER:�����ͣ��߹���...TANK:����ͣ�������ֵ...DEFENSIVE:�����ͣ��߷���...AGILE:�����ͣ��͹������
enum POKEMONKIND
{
	POWER, TANK, DEFENSIVE, AGILE
};

//�������ԣ�ˮ �� �� �� �� �� ľ �� �� �� ˮ
enum WUXINGTYPE
{
	SHUI, HUO, JIN, MU, TU
};

//�������ࣺ�����ͼ��ܣ���Ѫ�ͼ��ܣ���ǿ�Լ��������ļ��ܣ����Ͷ��ַ������ļ��ܣ���ǿ�Լ��Ĺ�����
enum SKILLKIND
{
	ATTACK, REHP, SELFDEFFENCE, OPPDEFEENCE, SELFATTACK
};

//�����Ƿ��Ѿ�ӵ��
enum OWN
{
	OWNED, NOTOWN
};

//������ʽ��
class SKILL {
public:
	string SkillName;//��������
	int SkillRank=1;//���ܵȼ�
	SKILLKIND SkillKind;//�������ࡣ����or����
	int SkillPower;//��������
	int SkillHit;//��������
	//int SkillPP;//Power Point��ʽ������ʣ���ʹ�ø���ʽ�Ĵ���
	OWN Selected=NOTOWN;
	SKILL();
	SKILL(string sname, int srank, SKILLKIND skind, int spower, int shit);
	SKILL(const SKILL &SK);
};

//�������
class POKEMON {
private:
	POKEMONKIND	Kind;//����
	string Name;//����
	int Rank=1;//�ȼ�:ÿ�������ʼ�ȼ�Ϊ1������15
	int Exp;//����ֵ��ս����ã�����100��һ����ÿ��һ����Ҫ��100����������100��200��300.������
	int	Hp;//����ֵ
	int	AtkInterval;//�����������λΪ10^-1s
	//�˺�=����2*�ȼ�+10��/250*������������/������������*��������+2��*�ӳ�  �ӳ�������������
	int Atk;//���������������ߵľ���ʹ��������ʽ���˺���
	int Def;//���������������ߵľ����ܵ�������ʽ���˺���
	//�����ж���A=��ʽ������*������������*(1-�������ر���)������һ��1��255֮�����������������С��Aʱ��Ϊ���У�����Ϊʧ��
	double Accuracy;//�����ʣ�������Խ����ʽԽ��������
	double Evasiveness;//�����ʣ�������Խ�ߣ��ܵ�����ʽԽ����������
	WUXINGTYPE wType;//��������
	SKILL AllSkills[SKILL_NUM];//���м����б�
	SKILL* GotSkills[SKILL_NUM];//�ѻ�õļ����б�ָ�����м����б�����Ӧ�ļ���
	int AllSkillCnt;
	int GotSkillCnt;//��ǰ�ѻ�õļ�����//�ǲ���Ӧ��Ū��public�����//�޸ĳ�ָ�룿����
	string Nick;//�ǳ�

public:
	POKEMON();//Ĭ�Ϲ��캯��
	POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk, 
		int xdef, int xhp, int xatki,double xaccuracy,double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);//��ֵ���캯��
	POKEMON(const POKEMON &PET);//�������캯��
	~POKEMON();
	void Input_Kind(POKEMONKIND xkind);
	POKEMONKIND Get_Kind()const;
	void Input_Name(string xname);
	string Get_Name()const;
	void Input_Rank(int xrank);
	int Get_Rank()const;
	void Input_Exp(int xexp);
	int Get_Exp()const;
	void Input_Atk(int xatk);
	int Get_Atk()const;
	void Input_Def(int xdef);
	int Get_Def()const;
	void Input_Hp(int xhp);
	int Get_Hp()const;
	void Input_AtkI(int xatki);
	int Get_AtkI()const;
	void Input_Accuracy(double xaccuracy);
	double Get_Accuracy()const;
	void Input_Evasiveness(double xevasiveness);
	double Get_Evasiveness()const;
	void Input_Type(WUXINGTYPE xtype);
	WUXINGTYPE Get_Type()const;
	void Input_GotSkillCnt(int xskillcnt);
	int Get_GotSkillCnt()const;
	void Input_ALLSkillCnt(int xskillcnt);
	int Get_ALLSkillCnt()const;
	void Input_Nick(string xnick);
	string Get_Nick()const;
	const SKILL *Access_AllSkill()const;//���ط������м����б��0λָ��
	SKILL *Access_GotSkill(int pos)const;//����ĳ���Ѿ�get���ļ���

	void RefershRank();//�õ�ǰ�ľ��龭��ֵ���µȼ���Ϣ
	//���Ӽ���
	//��������
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};

//-----------------------------------------------------------------------------------------
//�������͵ľ����ࣺ
//�����ͳ���С���飺�߹���
class POWERPET :public POKEMON{
public:
	POWERPET();
	POWERPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	POWERPET(const POWERPET& PET);

};
//����ͳ���С���飺������
class TANKPET :public POKEMON{
public:
	TANKPET();
	TANKPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	TANKPET(const TANKPET& PET);

};
//�����Գ���С���飺�߷���
class DEFENSIVEPET :public POKEMON{
public:
	DEFENSIVEPET();
	DEFENSIVEPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	DEFENSIVEPET(const DEFENSIVEPET& PET);

};
//�����ͳ���С���飺�͹������
class AGILEPET :public POKEMON{
public:
	AGILEPET();
	AGILEPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	AGILEPET(const AGILEPET& PET);

};
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
//����ľ�����
//��������1-5��->��������6-10��->������������11-15��,�߹���
class GYARADOS :public POWERPET {
public:
	GYARADOS();
	GYARADOS(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	GYARADOS(const GYARADOS& PET);
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};
//С����->������->�Ҹ���,�����
class HAPPINY :public TANKPET {
public:
	HAPPINY();
	HAPPINY(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	HAPPINY(const HAPPINY& PET);
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};
//�����(1-5����->�����(6-10����->ˮ����(11-15�������߷���
class SQUIRTLE :public DEFENSIVEPET{
//private:
//	SKILL Skills[SKILL_NUM];
public:
	SQUIRTLE();
	SQUIRTLE(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	SQUIRTLE(const SQUIRTLE& PET);
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};
//����x->����->��������y��������
class  MEWTWO :public AGILEPET {
public:
	MEWTWO();
	MEWTWO(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	MEWTWO(const MEWTWO& PET);
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};
//�����->������->������Х��Incineroar��������
class INCINEROAR :public POWERPET {
public:
	INCINEROAR();
	INCINEROAR(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	INCINEROAR(const INCINEROAR& PET);
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};

//С��Ȼ->��Ȼ��Wobbuffet�������
class WOBBUFFET :public TANKPET {
public:
	WOBBUFFET();
	WOBBUFFET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	WOBBUFFET(const WOBBUFFET& PET);
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};
//������Onix->�����Steelix->��������ߣ�������
class STEELIX :public DEFENSIVEPET {
public:
	STEELIX();
	STEELIX(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	STEELIX(const STEELIX& PET);
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};
//����Abra->�»���Kadabra->����Alakazam��������
class ALAKAZAM :public AGILEPET {
public:
	ALAKAZAM();
	ALAKAZAM(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	ALAKAZAM(const ALAKAZAM& PET);
	virtual void Upgrade();//�����������麯����
	virtual void SkillAll();//�������С��������м���
};
