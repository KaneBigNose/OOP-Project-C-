#pragma once

#include "BankingCommonDec1.h"

typedef Account* Account_PTR; // Account�� ������ ������ ��Ī�� ����

class AccountArray // Account Ŭ������ �����͸� �迭�� �����ϴ� Ŭ����
{
private:
	Account_PTR* acc; // Account�� �����͸� �����ϴ� ������
	int acc_len;
	AccountArray(const AccountArray& copy) {} // ���� ������ ����
	AccountArray operator=(const AccountArray& copy) {} // ���� ������ ����
public:
	AccountArray() {} // ����Ʈ ������
	AccountArray(int num); // ������
	Account_PTR& operator[](int num); // ������ []�� �����ε�
	Account_PTR operator[](int num) const; // ������ []�� �����ε� const��
	~AccountArray();
};