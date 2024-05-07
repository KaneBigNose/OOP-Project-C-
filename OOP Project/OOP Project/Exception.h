#pragma once
#include <iostream>
using namespace std;

class Exception // 예외 상황 처리 클래스
{
private:
public:
	virtual void ShowExceptionInfo() = 0;
};

class DepositException : public Exception // 입급 예외 상황 처리 클래스
{
private:
	int money;
public:
	DepositException(int money) : money(money) {}
	void ShowExceptionInfo()
	{
		cout << "입금하시려는 금액(" << this->money << ")이 잘못 되었습니다." << endl;
	}
};

class WithdrawException : public Exception // 출금 예외 상황 처리 클래스
{
private:
	int money;
public:
	WithdrawException(int money) : money(money) {}
	void ShowExceptionInfo()
	{
		cout << "출금하시려는 금액(" << this->money << ")이 잘못 되었습니다." << endl;
	}
};