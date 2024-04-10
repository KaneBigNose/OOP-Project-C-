#pragma once

#include "AccountHandler.h"
#include "BankingCommonDec1.h"

int main(void) //메인 함수
{
	AccountHandler acchad;
	int choice; //사용자로부터 입력받은 번호

	while (1)
	{
		acchad.ShowMenu();
		cout << "선택: ";
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
		default: //1~5가 아닌 다른 값을 입력했을 경우
			cout << "잘못된 값을 전달" << endl;
		}
	}
	return 0;
}