#pragma once

#include "Account.h"
#include "BankingCommonDec1.h"

typedef Account* Account_PTR; // Account�� ������ ������ ��Ī�� ����

template <class T>
class BoundCheckArray // Account Ŭ������ �����͸� �迭�� �����ϴ� Ŭ����
{
private:
	Account_PTR* acc; // Account�� �����͸� �����ϴ� ������
	int acc_len;
	BoundCheckArray(const BoundCheckArray& copy) : acc_len(copy.acc_len) { acc = NULL; } // ���� ������ ����
	BoundCheckArray operator=(const BoundCheckArray& copy) {} // ���� ������ ����
public:
	BoundCheckArray(); // ����Ʈ ������
	BoundCheckArray(int num); // ������
	Account_PTR& operator[](int num); // ������ []�� �����ε�
	Account_PTR operator[](int num) const; // ������ []�� �����ε� const��
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray() : acc_len() // ����Ʈ ������
{
	acc = new Account_PTR; // Account�� �����͸� �迭�� ���� �Ҵ���
}

template <class T>
BoundCheckArray<T>::BoundCheckArray(int num) : acc_len(num) // ������
{
	acc = new Account_PTR[num]; // Account�� �����͸� �迭�� ���� �Ҵ���
}

template <class T>
Account_PTR& BoundCheckArray<T>::operator[](int num) // ������ []�� �����ε�
{
	if (num < 0 || num >= MAX_ACCOUNT)
	{
		cout << "���� : ������ ��� ���� ����" << endl;
		exit(1);
	}
	return acc[num];
}

template <class T>
Account_PTR BoundCheckArray<T>::operator[](int num) const // ������ []�� �����ε� const��
{
	if (num < 0 || num >= MAX_ACCOUNT)
	{
		cout << "���� : ������ ��� ���� ����" << endl;
		exit(1);
	}
	return acc[num];
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]acc;
}