#pragma once
#include "BankingCommonDec1.h"

AccountHandler::AccountHandler() // ������
	: accNum(0) {}
void AccountHandler::ShowMenu() const // �޴� ��Ÿ���� ��� �Լ�
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}
void AccountHandler::ChoiceHowToMakeAccount(int choice) // ������ ���� ���� ���� ��� �Լ�
{
	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ���   2. �ſ�ŷڰ���" << endl;
	cout << "���� : "; cin >> choice;
	switch (choice)
	{
	case 1:
		MakeNormalAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default:
		cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
		break;
	}
}
void AccountHandler::MakeNormalAccount() // ���� ���� ���� ���� ��� �Լ�
{
	int id;
	char name[NAME_LEN];
	int money;
	int interest_rate;
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID : ";	cin >> id;
	cout << "��  �� : ";	cin >> name;
	cout << "�Աݾ� : ";	cin >> money;
	cout << "������ : "; cin >> interest_rate;
	cout << endl;
	accArr[accNum] = new NormalAccount(id, name, money, interest_rate);
	accNum++;
}
void AccountHandler::MakeHighCreditAccount() // �ſ� �ŷ� ���� ���� ��� �Լ�
{
	int id;
	char name[NAME_LEN];
	int money;
	int interest_rate;
	int credit_level;
	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID : ";	cin >> id;
	cout << "��  �� : ";	cin >> name;
	cout << "�Աݾ� : ";	cin >> money;
	cout << "������ : "; cin >> interest_rate;
	cout << "�ſ��� (1 to A, 2 to B, 3 to C): "; cin >> credit_level;
	cout << endl;
	switch (credit_level)
	{
	case 1:
		accArr[accNum] = new HighCreditAccount(id, name, money, interest_rate, CREDIT_LEVEL::LEVEL_A);
		accNum++;
		break;
	case 2:
		accArr[accNum] = new HighCreditAccount(id, name, money, interest_rate, CREDIT_LEVEL::LEVEL_B);
		accNum++;
		break;
	case 3:
		accArr[accNum] = new HighCreditAccount(id, name, money, interest_rate, CREDIT_LEVEL::LEVEL_C);
		accNum++;
		break;
	default:
		cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
		break;
	}
}
void AccountHandler::DepositMoney() // �Ա� ��� �Լ�
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID : ";	cin >> id;
	cout << "�Աݾ� : ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->return_ID() == id)
		{
			accArr[i]->DepositMoney(money);
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}
void AccountHandler::WithdrawMoney() // ��� ��� �Լ�
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID : ";	cin >> id;
	cout << "��ݾ� : ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->return_ID() == id)
		{
			accArr[i]->WithDrawMoney(money);
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}
void AccountHandler::ShowAllAccInfo() const // ���� ���� ��� �Լ�
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowInfo();
	}
}
AccountHandler::~AccountHandler() // �Ҹ���
{
	for (int i = 0; i < accNum; i++) { delete accArr[i]; } // ������ ���µ� �ϳ��� �Ҹ�
	cout << "��Ʈ�� ��ü �Ҹ�" << endl;
}