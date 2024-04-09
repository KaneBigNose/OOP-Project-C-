#pragma once

#include "BankingCommonDec1.h"

AccountArray::AccountArray(int num) : acc_len(num) // ������
{
	acc = new Account_PTR[num]; // Account�� �����͸� �迭�� ���� �Ҵ���
}
Account_PTR& AccountArray::operator[](int num) // ������ []�� �����ε�
{
	if (num < 0 || num >= MAX_ACCOUNT)
	{
		cout << "���� : ������ ��� ���� ����" << endl;
		exit(1);
	}
	return acc[num];
}
Account_PTR AccountArray::operator[](int num) const // ������ []�� �����ε� const��
{
	if (num < 0 || num >= MAX_ACCOUNT)
	{
		cout << "���� : ������ ��� ���� ����" << endl;
		exit(1);
	}
	return acc[num];
}
AccountArray::~AccountArray()
{
	delete []acc;
}