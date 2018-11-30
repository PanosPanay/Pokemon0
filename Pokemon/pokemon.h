#include<iostream>
#include<string.h>
using namespace std;
//POWER:�����ͣ��߹���...TANK:����ͣ�������ֵ...DEFENSIVE:�����ͣ��߷���...AGILE:�����ͣ��͹������
enum POKEMONKIND
{
	POWER, TANK, DEFENSIVE, AGILE
};
//�������;;;;;;���ܣ�������������������������������������������������������������������������������������������������
class POKEMON {
private:
	POKEMONKIND	Kind;//����
	string Name;//����
	int Rank;//�ȼ�
	int Exp;//����ֵ
	int Atk;//������
	int Def;//������
	int	Hp;//����ֵ
	int	AtkInterval;//�������
public:
	POKEMON();//Ĭ�Ϲ��캯��
	POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk, int xdef, int xhp, int xatki);//��ֵ���캯��
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
};