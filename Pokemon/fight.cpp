#include "fight.h"

void FIGHT::A_VS_B()
{
	srand((unsigned)time(NULL));
	//int Attacker;//0表示攻击方是A，1表示攻击方是B
	POKEMON *Attacker = NULL;
	int currentTime = 0;
	int Aorder = 0;
	int Border = 0;
	int SleepTime = 0;
	if (A.Get_AtkI() <= B.Get_AtkI())
	{
		Attacker = &A;
		currentTime += A.Get_AtkI();
	}
	else
	{
		Attacker = &B;
		currentTime += B.Get_AtkI();
	}
	while (A.Get_Hp() > 0 && B.Get_Hp() > 0)
	{
		//需要改变一下atki，注意和速度是相反的概念
		if (Attacker == &A)//A出招
		{
			//int theSkill = rand() % (A.Get_GotSkillCnt());//随机选取一个招式，或者加一个开关，让用户选择招式？？？？？？？？？？？？
			//if()
			//输出招式
			++Aorder;
		}
		else //B出招
		{
			//输出招式
			++Border;
		}
		int theSkill = rand() % (Attacker->Get_GotSkillCnt());//随机选取一个招式，或者加一个开关，让用户选择招式？？？？？？？？？？？？
		switch (Attacker->Access_GotSkill(theSkill)->SkillKind)
		{
		case ATTACK:
			//分析命中率和伤害函数
			break;
		case REHP:
			break;
		case SELFDEFFENCE:
			break;
		case OPPDEFEENCE:
			break;
		case SELFATTACK:
			break;
		default:
			break;
		}
		//下一个出招的精灵
		if (((Aorder + 1)*A.Get_AtkI()) < ((Border + 1)*B.Get_AtkI()))
		{
			Attacker = 0;
			SleepTime = ((Aorder + 1)*A.Get_AtkI()) - currentTime;
		}
		else
		{
			Attacker = 1;
			SleepTime = ((Aorder + 1)*B.Get_AtkI()) - currentTime;
		}
		//Sleep(SleepTime);///////////////////////////////////////////////
	}
	//战斗后增加宠物小精灵的经验
	if (A.Get_Hp() > 0)//A赢
	{
		int nowExp = A.Get_Exp();
		nowExp = nowExp + winExp;
		A.Input_Exp(nowExp);
		nowExp = B.Get_Exp();
		nowExp = nowExp + loseExp;
		B.Input_Exp(nowExp);
	}
	else if (B.Get_Hp() > 0)//B赢
	{
		int nowExp = B.Get_Exp();
		nowExp = nowExp + winExp;
		B.Input_Exp(nowExp);
		nowExp = A.Get_Exp();
		nowExp = nowExp + loseExp;
		A.Input_Exp(nowExp);
	}
	else//A、B平局（实际不会出现？）
	{
		int nowExp = A.Get_Exp();
		nowExp = nowExp + tieExp;
		A.Input_Exp(nowExp);
		nowExp = B.Get_Exp();
		nowExp = nowExp + tieExp;
		B.Input_Exp(nowExp);
	}
	//更新宠物等级信息
	A.RefershRank();
	B.RefershRank();//最后再把新的等级和经验返回给宠物
}
