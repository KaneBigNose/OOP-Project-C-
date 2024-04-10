#pragma once
#include "Account.h"

Account::Account(int accID, String cus_name, int money) //�Ϲ� ������
	:accID(accID), remain_money(money)
{
	this->cus_name = cus_name;
}
void Account::DepositMoney(int money) //�Ա� ���� ��� �Լ�
{
	this->remain_money += money;
	cout << "�ԱݿϷ�" << endl << endl;
}
void Account::WithDrawMoney(int money) //��� ��� �Լ�
{
	if (this->remain_money < money)
	{
		cout << "�ܾ׺���" << endl << endl;
		return;
	}

	this->remain_money -= money;
	cout << "��ݿϷ�" << endl << endl;
}
void Account::ShowInfo() const //������ ��Ÿ���� ��� �Լ�
{
	cout << "����ID : " << this->accID << endl;
	cout << "��  �� : " << this->cus_name << endl;
	cout << "��  �� : " << this->remain_money << endl;
	cout << "������ : " << GetInterestRate() << "%" << endl << endl;
}
int Account::GetInterestRate() const
{
	return 0;
}