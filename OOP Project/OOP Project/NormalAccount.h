#pragma once
#include "Account.h"

class NormalAccount : public Account // 보통 예금 계좌 클래스
{
private:
	int interest_rate; // 이자율
public:
	NormalAccount(int accID, char* cus_name, int money, int interest_rate)
		: Account(accID, cus_name, money), interest_rate(interest_rate) {}
	virtual void DepositMoney(int money) // 입금 시 이자를 추가로 지급하는 형식의 가상 멤버 함수
	{
		Account::DepositMoney(money);
		AddInterestMoney();
	}
	void AddInterestMoney() // 이자를 더하는 멤버 함수
	{
		Account::DepositMoney((int)(return_remain_money() * interest_rate / 100.0));
	}
	int GetInterestRate() const
	{
		return interest_rate;
	}
};