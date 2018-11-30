#include<iostream>
#include<string.h>
using namespace std;
const int SKILL_NUM = 20;//设定一个精灵可以拥有的技能数上限为20
//POWER:力量型，高攻击...TANK:肉盾型，高生命值...DEFENSIVE:防御型，高防御...AGILE:敏捷型，低攻击间隔
enum POKEMONKIND
{
	POWER, TANK, DEFENSIVE, AGILE
};
//五行属性：水 克 火 克 金 克 木 克 土 克 水
enum WUXINGTYPE
{
	SHUI, HUO, JIN, MU, TU
};
//技能种类：攻击和防御
enum SKILLKIND
{
	ATTACK, DEFFENCE
};
//技能招式类
class SKILL {
public:
	string SkillName;//技能名称
	int SkillRank;//技能等级
	int SkillKind;//技能种类。攻击or防御
	int SkillPower;//技能威力
	int SkillHit;//技能命中
	int SkillPP;//Power Point招式点数，剩余可使用该招式的次数
};
//宠物基类;;;;;;技能？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
class POKEMON {
private:
	POKEMONKIND	Kind;//种类
	string Name;//名字
	int Rank;//等级:每个精灵初始等级为1，满级15集
	int Exp;//经验值
	int	Hp;//生命值
	int	AtkInterval;//攻击间隔：速度，只要速度高出对方1点就能比对方先出手；若速度一样，攻击次序则随机。 
	//伤害=（（2*等级+10）/250*攻击方攻击力/防御方防御力*技能威力+2）*加成  加成由属性相克造成
	int Atk;//攻击力：攻击力高的精灵使用物理招式的伤害多
	int Def;//防御力：防御力高的精灵受到物理招式的伤害少
	//命中判定：A=招式的命中*攻击方命中率*防御方回避率。产生一个1～255之间的随机数，该随机数小于A时视为命中，否则为失误。
	double Accuracy;//命中率：命中率越高招式越容易命中
	double Evasiveness;//闪避率：闪避率越高，受到的招式越不容易命中
	WUXINGTYPE wType;//五行属性
	SKILL Skills[SKILL_NUM];//技能列表
	int SkillCnt;//当前技能数
public:
	POKEMON();//默认构造函数
	POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk, 
		int xdef, int xhp, int xatki,double xaccuracy,double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt);//赋值构造函数
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
	void Input_Accuracy(double xaccuracy);
	double Get_Accuracy();
	void Input_Evasiveness(double xevasiveness);
	double Get_Evasiveness();
	void Input_Type(WUXINGTYPE xtype);
	WUXINGTYPE Get_Type();
	void Input_SkillCnt(int xskillcnt);
	int Get_SkillCnt();
	//增加技能
	//攻击函数
};