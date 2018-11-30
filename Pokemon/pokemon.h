#include<iostream>
#include<string.h>
using namespace std;
const int SKILL_NUM = 20;//�趨һ���������ӵ�еļ���������Ϊ20

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

//�������ࣺ�����ͼ��ܣ���Ѫ�ͼ��ܣ���ǿ�Լ��������ļ��ܣ����Ͷ��ַ������ļ���
enum SKILLKIND
{
	ATTACK, REHP, SELFDEFFENCE, OPPDEFEENCE
};

//������ʽ��
class SKILL {
public:
	string SkillName;//��������
	int SkillRank;//���ܵȼ�
	SKILLKIND SkillKind;//�������ࡣ����or����
	int SkillPower;//��������
	int SkillHit;//��������
	//int SkillPP;//Power Point��ʽ������ʣ���ʹ�ø���ʽ�Ĵ���
	
	SKILL();
	SKILL(string sname, int srank, SKILLKIND skind, int spower, int shit);
	SKILL(const SKILL &SK);
};

//�������
class POKEMON {
private:
	POKEMONKIND	Kind;//����
	string Name;//����
	int Rank;//�ȼ�:ÿ�������ʼ�ȼ�Ϊ1������15
	int Exp;//����ֵ
	int	Hp;//����ֵ
	int	AtkInterval;//����������ٶȣ�ֻҪ�ٶȸ߳��Է�1����ܱȶԷ��ȳ��֣����ٶ�һ������������������� 
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
	SKILL *Access_AllSkill();//���ط������м����б��0λָ��

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
	TANKPET();
	TANKPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	TANKPET(const TANKPET& PET);

};
//�����Գ���С���飺�߷���
class DEFENSIVEPET :public POKEMON{
	DEFENSIVEPET();
	DEFENSIVEPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	DEFENSIVEPET(const DEFENSIVEPET& PET);

};
//�����ͳ���С���飺�͹������
class AGILEPET :public POKEMON{
	AGILEPET();
	AGILEPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick, int xallSkillcnt);
	AGILEPET(const AGILEPET& PET);

};
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
//����ľ�����
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

//��������1-7��->��������7-15��,�߹���
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