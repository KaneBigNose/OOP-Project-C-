#pragma once
#include <iostream>
using namespace std;

class Exception // ���� ��Ȳ ó�� Ŭ����
{
private:
public:
	virtual void ShowExceptionInfo() = 0;
};

class DepositException : public Exception // �Ա� ���� ��Ȳ ó�� Ŭ����
{
private:
	int money;
public:
	DepositException(int money) : money(money) {}
	void ShowExceptionInfo()
	{
		cout << "�Ա��Ͻ÷��� �ݾ�(" << this->money << ")�� �߸� �Ǿ����ϴ�." << endl;
	}
};

class WithdrawException : public Exception // ��� ���� ��Ȳ ó�� Ŭ����
{
private:
	int money;
public:
	WithdrawException(int money) : money(money) {}
	void ShowExceptionInfo()
	{
		cout << "����Ͻ÷��� �ݾ�(" << this->money << ")�� �߸� �Ǿ����ϴ�." << endl;
	}
};