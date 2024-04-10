#pragma once

#include "Account.h"

typedef Account* Account_PTR; // Account�� ������ ������ ��Ī�� ����

class AccountArray // Account Ŭ������ �����͸� �迭�� �����ϴ� Ŭ����
{
private:
	Account_PTR* acc; // Account�� �����͸� �����ϴ� ������
	int acc_len;
	AccountArray(const AccountArray& copy) : acc_len(copy.acc_len) { acc = NULL; } // ���� ������ ����
	AccountArray operator=(const AccountArray& copy) {} // ���� ������ ����
public:
	AccountArray(); // ����Ʈ ������
	AccountArray(int num); // ������
	Account_PTR& operator[](int num); // ������ []�� �����ε�
	Account_PTR operator[](int num) const; // ������ []�� �����ε� const��
	~AccountArray();
};