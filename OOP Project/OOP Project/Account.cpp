#pragma once
#include "BankingCommonDec1.h"

Account::Account(int accID, char* cus_name, int money) //일반 생성자
	:accID(accID), remain_money(money)
{
	this->cus_name = new char[strlen(cus_name) + 1];
	strcpy_s(this->cus_name, NAME_LEN, cus_name);
}
Account::Account(const Account& copy) //복사 생성자
	:accID(copy.accID), remain_money(copy.remain_money)
{
	this->cus_name = new char[strlen(copy.cus_name) + 1];
	strcpy_s(this->cus_name, NAME_LEN, copy.cus_name);
}
Account Account::operator=(Account& copy) // 대입 연산자
{
	this->accID = copy.accID;
	this->remain_money = copy.remain_money;
	this->cus_name = new char[strlen(copy.cus_name) + 1];
	strcpy_s(this->cus_name, NAME_LEN, copy.cus_name);
}
int Account::return_ID() const { return accID; } //ID에 접근하는 멤버 함수
int Account::return_remain_money() const { return remain_money; } //금액에 접근하는 멤버 함수
char* Account::return_cusname() const { return cus_name; } //이름에 접근하는 멤버 함수
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
	cout << "계좌ID: " << this->accID << endl;
	cout << "이  름: " << this->cus_name << endl;
	cout << "잔  액: " << this->remain_money << endl << endl;
}
Account::~Account() //소멸자
{
	delete[]cus_name;
	cout << "생성된 계좌 소멸" << endl;
}