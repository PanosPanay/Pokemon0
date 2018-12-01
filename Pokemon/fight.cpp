#include "fight.h"

void FIGHT::A_VS_B()
{
	while (A.Get_Hp() > 0 && B.Get_Hp() > 0)
	{

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
