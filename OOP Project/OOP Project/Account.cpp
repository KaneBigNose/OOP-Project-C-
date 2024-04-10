#pragma once
#include "Account.h"

Account::Account(int accID, String cus_name, int money) //일반 생성자
	:accID(accID), remain_money(money)
{
	this->cus_name = cus_name;
}
void Account::DepositMoney(int money) //입금 가상 멤버 함수
{
	this->remain_money += money;
	cout << "입금완료" << endl << endl;
}
void Account::WithDrawMoney(int money) //출금 멤버 함수
{
	if (this->remain_money < money)
	{
		cout << "잔액부족" << endl << endl;
		return;
	}

	this->remain_money -= money;
	cout << "출금완료" << endl << endl;
}
void Account::ShowInfo() const //정보를 나타내는 멤버 함수
{
	cout << "계좌ID : " << this->accID << endl;
	cout << "이  름 : " << this->cus_name << endl;
	cout << "잔  액 : " << this->remain_money << endl;
	cout << "이자율 : " << GetInterestRate() << "%" << endl << endl;
}
int Account::GetInterestRate() const
{
	return 0;
}