#pragma once

#include "AccountHandler.h"
#include "BankingCommonDec1.h"

int main(void) //���� �Լ�
{
	AccountHandler acchad;
	int choice; //����ڷκ��� �Է¹��� ��ȣ

	while (1)
	{
		acchad.ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			acchad.ChoiceHowToMakeAccount(choice);
			break;
		case DEPOSIT:
			acchad.DepositMoney();
			break;
		case WITHDRAW:
			acchad.WithdrawMoney();
			break;
		case INQUIRE:
			acchad.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default: //1~5�� �ƴ� �ٸ� ���� �Է����� ���
			cout << "�߸��� ���� ����" << endl;
		}
	}
	return 0;
}