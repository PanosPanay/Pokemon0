#include "fight.h"

void FIGHT::A_VS_B()
{
	srand((unsigned)time(NULL));
	//int Attacker;//0��ʾ��������A��1��ʾ��������B
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
		//��Ҫ�ı�һ��atki��ע����ٶ����෴�ĸ���
		if (Attacker == &A)//A����
		{
			//int theSkill = rand() % (A.Get_GotSkillCnt());//���ѡȡһ����ʽ�����߼�һ�����أ����û�ѡ����ʽ������������������������
			//if()
			//�����ʽ
			++Aorder;
		}
		else //B����
		{
			//�����ʽ
			++Border;
		}
		int theSkill = rand() % (Attacker->Get_GotSkillCnt());//���ѡȡһ����ʽ�����߼�һ�����أ����û�ѡ����ʽ������������������������
		switch (Attacker->Access_GotSkill(theSkill)->SkillKind)
		{
		case ATTACK:
			//���������ʺ��˺�����
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
		//��һ�����еľ���
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
