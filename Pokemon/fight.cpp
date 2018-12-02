#include "fight.h"

FIGHT::FIGHT()
{
}

FIGHT::FIGHT(POKEMON *F1, POKEMON *F2)
{
	realA = F1;
	realB = F2;
	A = *realA;
	B = *realB;
}

FIGHT::FIGHT(const FIGHT & theFight)
{
	realA = theFight.realA;
	realB = theFight.realB;
	A = theFight.A;
	B = theFight.B;
}

void FIGHT::A_VS_B()
{
	srand((unsigned)time(NULL));
	//int Attacker;//0��ʾ��������A��1��ʾ��������B
	POKEMON *Attacker = NULL;
	POKEMON *Defender = NULL;
	int currentTime = 0;
	int Aorder = 0;
	int Border = 0;
	int SleepTime = 0;
	if (A.Get_AtkI() <= B.Get_AtkI())
	{
		Attacker = &A;
		currentTime += A.Get_AtkI();
		Defender = &B;
	}
	else
	{
		Attacker = &B;
		currentTime += B.Get_AtkI();
		Defender = &A;
	}
	//���ս��˫����ǰ����ֵ
	cout << "ս����ʼ��" << endl;
	cout << attackName << ": " << "HP=" << Attacker->Get_Hp() << ", Atk=" << Attacker->Get_Atk()
		<< ", Def=" << Attacker->Get_Def() << ", Accuracy=" << Attacker->Get_Accuracy() << ", Evasiveness="
		<< Attacker->Get_Evasiveness() << endl;
	cout << defenderName << ": " << "HP=" << Defender->Get_Hp() << ", Atk=" << Defender->Get_Atk()
		<< ", Def=" << Defender->Get_Def() << ", Accuracy=" << Defender->Get_Accuracy() << ", Evasiveness="
		<< Defender->Get_Evasiveness() << endl << endl;
	while (A.Get_Hp() > 0 && B.Get_Hp() > 0)
	{
		//��Ҫ�ı�һ��atki��ע����ٶ����෴�ĸ���
		if (Attacker == &A)//A����
		{
			++Aorder;
		}
		else //B����
		{
			++Border;
		}
		//ȷ����ʽ�����
		string defenderName = Defender->Get_Name();
		string attackName = Attacker->Get_Name();
		int theSkill = rand() % (Attacker->Get_GotSkillCnt());//���ѡȡһ����ʽ�����߼�һ�����أ����û�ѡ����ʽ������������������������
		SKILL* theSkillPtr = Attacker->Access_GotSkill(theSkill);
		cout << "��ʽ" << Aorder + Border << ":" << endl;
		cout << attackName << "����" << theSkillPtr->SkillName << endl;
		//��������
		int theHitNum = (theSkillPtr->SkillHit)*(Attacker->Get_Accuracy())*(1 - (Defender->Get_Evasiveness())) * 100;
		int isHit = rand() % 100 + 1;
		switch (theSkillPtr->SkillKind)
		{
		case ATTACK:
			//���������ʺ��˺�����
			double addition = 1;//�ӳɣ��������
			if (Defender->Get_Type() - Attacker->Get_Type() == 1 || Defender->Get_Type() - Attacker->Get_Type() == 4)
				addition = 1.2;
			else if (Attacker->Get_Type() - Defender->Get_Type() == 1 || Attacker->Get_Type() - Defender->Get_Type() == 4)
				addition = 0.8;
			
			if (isHit <= theHitNum)//����
			{
				int hurt = (Attacker->Get_Atk() / Attacker->Get_Def())*theSkillPtr->SkillPower*addition;
				int theHp = Defender->Get_Hp();
				if (theHp > hurt)
					theHp = theHp - hurt;
				else
					theHp = 0;
				Defender->Input_Hp(theHp);
				cout << "���У�" << defenderName << "�ܵ�" << hurt << "���˺���" << endl;
			}
			else
			{
				cout << "δ���У�" << defenderName << "���ɵض���˹�����" << endl;
			}
			break;
		case REHP:
			if (isHit <= theHitNum)//�ɹ�ʹ����ʽ��Ѫ
			{
				int theHp = Attacker->Get_Hp();
				theHp = theHp + theSkillPtr->SkillPower;
				Attacker->Input_Hp(theHp);
				cout << "�ɹ���Ѫ��" << attackName << "����ֵ����" << theSkillPtr->SkillPower << "��" << endl;
			}
			else
			{
				cout << "��Ѫʧ�ܣ�" << endl;
			}
			break;
		case SELFDEFFENCE:
			if (isHit <= theHitNum)//�ɹ�ʹ����ʽ�������������
			{
				int theDef = Attacker->Get_Def();
				theDef = theDef + theSkillPtr->SkillPower;
				Attacker->Input_Def(theDef);
				cout << "�ɹ����У�" << attackName << "����������" << theSkillPtr->SkillPower << "��" << endl;
			}
			else
			{
				cout << "����������ʧ�ܣ�" << endl;
			}
			break;
		case OPPDEFEENCE:
			if (isHit <= theHitNum)//�ɹ�ʹ����ʽ���ͶԷ�������
			{
				int theDef = Attacker->Get_Def();
				if (theDef - theSkillPtr->SkillPower > 10)//����������Ϊ10
				{
					theDef = theDef - theSkillPtr->SkillPower;
					cout << "�ɹ����У�" << defenderName << "����������" << theSkillPtr->SkillPower << "��" << endl;
				}
				else
				{					
					cout << "�ɹ����У�" << defenderName << "���������͵����ޣ�10�㣩" << endl;
					theDef = 10;
				}				
				Attacker->Input_Def(theDef);
			}
			else
			{
				cout << "δ�ܶԵз����������ʵ������в��" << endl;
			}
			break;
		case SELFATTACK:
			if (isHit <= theHitNum)//�ɹ�ʹ����ʽ������������
			{
				int theAtk = Attacker->Get_Atk();
				theAtk = theAtk + theSkillPtr->SkillPower;
				Attacker->Input_Atk(theAtk);
				cout << "�ɹ����У�" << attackName << "����������" << theSkillPtr->SkillPower << "��" << endl;
			}
			else
			{
				cout << "����������ʧ�ܣ�" << endl;
			}
			break;
		default:
			break;
		}
		//���ս��˫����ǰ����ֵ
		cout << attackName << ": " << "HP=" << Attacker->Get_Hp() << ", Atk=" << Attacker->Get_Atk()
			<< ", Def=" << Attacker->Get_Def() << ", Accuracy=" << Attacker->Get_Accuracy() << ", Evasiveness="
			<< Attacker->Get_Evasiveness() << endl;
		cout << defenderName << ": " << "HP=" << Defender->Get_Hp() << ", Atk=" << Defender->Get_Atk()
			<< ", Def=" << Defender->Get_Def() << ", Accuracy=" << Defender->Get_Accuracy() << ", Evasiveness="
			<< Defender->Get_Evasiveness() << endl << endl;
		//���ü��ʽ��;���������ʺ�������
		//��һ�����еľ���
		if (((Aorder + 1)*A.Get_AtkI()) < ((Border + 1)*B.Get_AtkI()))
		{
			Attacker = &A;
			Defender = &B;
			SleepTime = ((Aorder + 1)*A.Get_AtkI()) - currentTime;
		}
		else
		{
			Attacker = &B;
			Defender = &A;
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
	B.RefershRank();
	//����Ƿ�������
	if (A.Get_Rank() > realA->Get_Rank())//����
	{
		//����ٰ��µĵȼ��;��鷵�ظ�����
		realA->Input_Exp(A.Get_Exp());
		realA->Input_Rank(A.Get_Rank());
		realA->Upgrade();//������������
	}
	else
	{
		realA->Input_Exp(A.Get_Exp());
		realA->Input_Rank(A.Get_Rank());
	}
	if (B.Get_Rank() > realB->Get_Rank())
	{
		realB->Input_Exp(B.Get_Exp());
		realB->Input_Rank(B.Get_Rank());
		realB->Upgrade();
	}
	else
	{
		realB->Input_Exp(B.Get_Exp());
		realB->Input_Rank(B.Get_Rank());
	}
	
}

