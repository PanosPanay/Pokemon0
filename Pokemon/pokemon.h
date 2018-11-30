#include<iostream>
#include<string.h>
using namespace std;
//POWER:力量型，高攻击...TANK:肉盾型，高生命值...DEFENSIVE:防御型，高防御...AGILE:敏捷型，低攻击间隔
enum POKEMONKIND
{
	POWER, TANK, DEFENSIVE, AGILE
};
//宠物基类;;;;;;技能？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
class POKEMON {
private:
	POKEMONKIND	Kind;//种类
	string Name;//名字
	int Rank;//等级
	int Exp;//经验值
	int Atk;//攻击力
	int Def;//防御力
	int	Hp;//生命值
	int	AtkInterval;//攻击间隔
public:
	POKEMON();//默认构造函数
	POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk, int xdef, int xhp, int xatki);//赋值构造函数
	POKEMON(const POKEMON &PET);//拷贝构造函数
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