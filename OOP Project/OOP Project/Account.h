#pragma once 

#include "String.h"

class Account //���� Ŭ����
{
private:
	int accID;
	int remain_money;
	String cus_name;
public:
	Account() : accID(0), remain_money(0) {} // ����Ʈ ������
	Account(int accID, String cus_name, int money); // �Ϲ� ������

	int Get_ID() const { return accID; } //ID�� �����ϴ� ��� �Լ�
	int Get_remain_money() const { return remain_money; } //�ݾ׿� �����ϴ� ��� �Լ�
	String Get_cusname() const { return cus_name; } //�̸��� �����ϴ� ��� �Լ�

	virtual void DepositMoney(int money); // �Ա� ���� ��� �Լ�
	void WithDrawMoney(int money); // ��� ��� �Լ�
	void ShowInfo() const; // ������ ��Ÿ���� ��� �Լ�
	virtual int GetInterestRate() const; // �������� ��ȯ�ϴ� �Լ�
};