#include "fight.h"

void FIGHT::A_VS_B()
{
	while (A.Get_Hp() > 0 && B.Get_Hp() > 0)
	{

	}
	//ս�������ӳ���С����ľ���
	if (A.Get_Hp() > 0)//AӮ
	{
		int nowExp = A.Get_Exp();
		nowExp = nowExp + winExp;
		A.Input_Exp(nowExp);
		nowExp = B.Get_Exp();
		nowExp = nowExp + loseExp;
		B.Input_Exp(nowExp);
	}
	else if (B.Get_Hp() > 0)//BӮ
	{
		int nowExp = B.Get_Exp();
		nowExp = nowExp + winExp;
		B.Input_Exp(nowExp);
		nowExp = A.Get_Exp();
		nowExp = nowExp + loseExp;
		A.Input_Exp(nowExp);
	}
	else//A��Bƽ�֣�ʵ�ʲ�����֣���
	{
		int nowExp = A.Get_Exp();
		nowExp = nowExp + tieExp;
		A.Input_Exp(nowExp);
		nowExp = B.Get_Exp();
		nowExp = nowExp + tieExp;
		B.Input_Exp(nowExp);
	}
	//���³���ȼ���Ϣ
	A.RefershRank();
	B.RefershRank();//����ٰ��µĵȼ��;��鷵�ظ�����
}
