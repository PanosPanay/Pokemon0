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
//�������ࣺ�����ͷ���
enum SKILLKIND
{
	ATTACK, DEFFENCE
};
//������ʽ��
class SKILL {
public:
	string SkillName;//��������
	int SkillRank;//���ܵȼ�
	int SkillKind;//�������ࡣ����or����
	int SkillPower;//��������
	int SkillHit;//��������
	int SkillPP;//Power Point��ʽ������ʣ���ʹ�ø���ʽ�Ĵ���
};
//�������;;;;;;���ܣ�������������������������������������������������������������������������������������������������
class POKEMON {
private:
	POKEMONKIND	Kind;//����
	string Name;//����
	int Rank;//�ȼ�:ÿ�������ʼ�ȼ�Ϊ1������15��
	int Exp;//����ֵ
	int	Hp;//����ֵ
	int	AtkInterval;//����������ٶȣ�ֻҪ�ٶȸ߳��Է�1����ܱȶԷ��ȳ��֣����ٶ�һ������������������� 
	//�˺�=����2*�ȼ�+10��/250*������������/������������*��������+2��*�ӳ�  �ӳ�������������
	int Atk;//���������������ߵľ���ʹ��������ʽ���˺���
	int Def;//���������������ߵľ����ܵ�������ʽ���˺���
	//�����ж���A=��ʽ������*������������*�������ر��ʡ�����һ��1��255֮�����������������С��Aʱ��Ϊ���У�����Ϊʧ��
	double Accuracy;//�����ʣ�������Խ����ʽԽ��������
	double Evasiveness;//�����ʣ�������Խ�ߣ��ܵ�����ʽԽ����������
	WUXINGTYPE wType;//��������
	SKILL Skills[SKILL_NUM];//�����б�
	int SkillCnt;//��ǰ������
public:
	POKEMON();//Ĭ�Ϲ��캯��
	POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk, 
		int xdef, int xhp, int xatki,double xaccuracy,double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt);//��ֵ���캯��
	POKEMON(const POKEMON &PET);//�������캯��
	~POKEMON();
	void Input_Kind(POKEMONKIND xkind);
	POKEMONKIND Get_Kind();
	void Input_Name(string xname);
	string Get_Name();
	void Input_Rank(int xrank);
	int Get_Rank();
	void Input_Exp(int xexp);
	int Get_Exp();
	void Input_Atk(int xatk);
	int Get_Atk();
	void Input_Def(int xdef);
	int Get_Def();
	void Input_Hp(int xhp);
	int Get_Hp();
	void Input_AtkI(int xatki);
	int Get_AtkI();
	void Input_Accuracy(double xaccuracy);
	double Get_Accuracy();
	void Input_Evasiveness(double xevasiveness);
	double Get_Evasiveness();
	void Input_Type(WUXINGTYPE xtype);
	WUXINGTYPE Get_Type();
	void Input_SkillCnt(int xskillcnt);
	int Get_SkillCnt();
	//���Ӽ���
	//��������
};