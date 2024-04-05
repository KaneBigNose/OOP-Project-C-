#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount // �ſ� �ŷ� ���� Ŭ����
{
private:
	int credit_level; // �ſ� ���
public:
	HighCreditAccount(int accID, char* cus_name, int money, double interest_rate, int credit_level)
		: NormalAccount(accID, cus_name, money, interest_rate + credit_level), credit_level(credit_level) {}
};
