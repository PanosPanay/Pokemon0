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

//宠物基类
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
	SKILL AllSkills[SKILL_NUM];//所有技能列表
	SKILL* GotSkills[SKILL_NUM];//已获得的技能列表，指向所有技能列表中相应的技能
	int SkillCnt;//当前技能数//是不是应该弄成public方便点//修改成指针？？？
	string Nick;//昵称
public:
	POKEMON();//默认构造函数
	POKEMON(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk, 
		int xdef, int xhp, int xatki,double xaccuracy,double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick);//赋值构造函数
	POKEMON(const POKEMON &PET);//拷贝构造函数
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
	void Input_SkillCnt(int xskillcnt);
	int Get_SkillCnt()const;
	void Input_Nick(string xnick);
	string Get_Nick()const;

	//增加技能
	//攻击函数
	virtual void Upgrade();//升级函数（虚函数）
	virtual void SkillAll();//存入该类小精灵的所有技能
};

//-----------------------------------------------------------------------------------------
//四种类型的精灵类：
//力量型宠物小精灵：高攻击
class POWERPET :public POKEMON{
public:
	POWERPET();
	POWERPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick);
	POWERPET(const POWERPET& PET);

};
//肉盾型宠物小精灵：高生命
class TANKPET :public POKEMON{
	TANKPET();
	TANKPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick);
	TANKPET(const TANKPET& PET);

};
//防御性宠物小精灵：高防御
class DEFENSIVEPET :public POKEMON{
	DEFENSIVEPET();
	DEFENSIVEPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick);
	DEFENSIVEPET(const DEFENSIVEPET& PET);

};
//敏捷型宠物小精灵：低攻击间隔
class AGILEPET :public POKEMON{
	AGILEPET();
	AGILEPET(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick);
	AGILEPET(const AGILEPET& PET);

};
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
//具体的精灵类
//杰尼龟(1-5级）->卡咪龟(6-10级）->水箭龟(11-15级），高防御
class SQUIRTLE :public DEFENSIVEPET{
//private:
//	SKILL Skills[SKILL_NUM];
public:
	SQUIRTLE();
	SQUIRTLE(POKEMONKIND xkind, string xname, int xrank, int xexp, int xatk,
		int xdef, int xhp, int xatki, double xaccuracy, double xevasiveness,
		WUXINGTYPE xtype, int xskillcnt, string xnick);
	SQUIRTLE(const SQUIRTLE& PET);
	virtual void Upgrade();//升级函数（虚函数）
	virtual void SkillAll();//存入该类小精灵的所有技能
};