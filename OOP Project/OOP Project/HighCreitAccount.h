#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount // 신용 신뢰 계좌 클래스
{
private:
	int credit_level; // 신용 등급
public:
	HighCreditAccount(int accID, char* cus_name, int money, double interest_rate, int credit_level)
		: NormalAccount(accID, cus_name, money, interest_rate + credit_level), credit_level(credit_level) {}
};
