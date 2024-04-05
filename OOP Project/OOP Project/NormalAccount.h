#pragma once
#include "Account.h"

class NormalAccount : public Account // ���� ���� ���� Ŭ����
{
private:
	int interest_rate; // ������
public:
	NormalAccount(int accID, char* cus_name, int money, int interest_rate)
		: Account(accID, cus_name, money), interest_rate(interest_rate) {}
	virtual void DepositMoney(int money) // �Ա� �� ���ڸ� �߰��� �����ϴ� ������ ���� ��� �Լ�
	{
		Account::DepositMoney(money);
		AddInterestMoney();
	}
	void AddInterestMoney() // ���ڸ� ���ϴ� ��� �Լ�
	{
		Account::DepositMoney((int)(return_remain_money() * interest_rate / 100.0));
	}
	int GetInterestRate() const
	{
		return interest_rate;
	}
};