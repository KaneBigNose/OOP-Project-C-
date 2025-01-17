#pragma once

#include "AccountHandler.h"
#include "String.h"
#include "NormalAccount.h"
#include "HighCreitAccount.h"

AccountHandler::AccountHandler() // 생성자
	: accNum(0) {}
void AccountHandler::ShowMenu() const // 메뉴 나타내기 멤버 함수
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void AccountHandler::ChoiceHowToMakeAccount(int choice) // 생성할 계좌 유형 설정 멤버 함수
{
	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌   2. 신용신뢰계좌" << endl;
	cout << "선택 : "; cin >> choice;
	switch (choice)
	{
	case 1:
		MakeNormalAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default:
		cout << "잘못된 값을 입력하였습니다." << endl;
		break;
	}
}
void AccountHandler::MakeNormalAccount() // 보통 예금 계좌 개설 멤버 함수
{
	int id;
	String name;
	int money;
	int interest_rate;
	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID : ";	cin >> id;
	cout << "이  름 : ";	cin >> name;
	cout << "입금액 : ";	cin >> money;
	cout << "이자율 : "; cin >> interest_rate;
	cout << endl;
	accArr[accNum] = new NormalAccount(id, name, money, interest_rate);
	cout << "Error";
	accNum++;
}
void AccountHandler::MakeHighCreditAccount() // 신용 신뢰 계좌 개설 멤버 함수
{
	int id;
	String name;
	int money;
	int interest_rate;
	int credit_level;
	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID : ";	cin >> id;
	cout << "이  름 : ";	cin >> name;
	cout << "입금액 : ";	cin >> money;
	cout << "이자율 : "; cin >> interest_rate;
	cout << "신용등급 (1 to A, 2 to B, 3 to C): "; cin >> credit_level;
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
		cout << "잘못된 값을 입력하였습니다." << endl;
		break;
	}
}
void AccountHandler::DepositMoney() // 입금 멤버 함수
{
	int money;
	int id;
	while (1)
	{
		cout << "[입    금]" << endl;
		cout << "계좌ID : ";	cin >> id;
		cout << "입금액 : ";	cin >> money;
		try
		{
			if (money < 0) // 예외상황
			{
				throw DepositException(money);
			}
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->Get_ID() == id)
				{
					accArr[i]->DepositMoney(money);
					break;
				}
			}
			cout << "유효하지 않은 ID 입니다." << endl << endl;
		}
		catch (Exception& exct) // 예외처리
		{
			exct.ShowExceptionInfo();
			cout << "입금하실 금액을 다시 입력해주시길 바랍니다." << endl;
		}
	}
}
void AccountHandler::WithdrawMoney() // 출금 멤버 함수
{
	int money;
	int id;
	while (1)
	{
		cout << "[출    금]" << endl;
		cout << "계좌ID : ";	cin >> id;
		cout << "출금액 : ";	cin >> money;
		try
		{
			if (money < 0) // 예외상황
			{
				throw WithdrawException(money);
			}
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->Get_ID() == id)
				{
					if (accArr[i]->Get_remain_money() < money)
					{
						throw WithdrawException(money);
					}
					accArr[i]->WithDrawMoney(money);
					break;
				}
			}
			cout << "유효하지 않은 ID 입니다." << endl << endl;
		}
		catch (Exception& exct) // 예외처리
		{
			exct.ShowExceptionInfo();
			cout << "출금하실 금액을 다시 입력해주시길 바랍니다." << endl;
		}
	}
}
void AccountHandler::ShowAllAccInfo() const // 정보 제공 멤버 함수
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowInfo();
	}
}
AccountHandler::~AccountHandler() // 소멸자
{
	for (int i = 0; i < accNum; i++) { delete accArr[i]; } // 생성된 계좌들 하나씩 소멸
	cout << "컨트롤 객체 소멸" << endl;
}