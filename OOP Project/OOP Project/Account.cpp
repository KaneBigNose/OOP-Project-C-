#pragma once
#include "BankingCommonDec1.h"

Account::Account(int accID, char* cus_name, int money) //�Ϲ� ������
	:accID(accID), remain_money(money)
{
	this->cus_name = new char[strlen(cus_name) + 1];
	strcpy_s(this->cus_name, NAME_LEN, cus_name);
}
Account::Account(const Account& copy) //���� ������
	:accID(copy.accID), remain_money(copy.remain_money)
{
	this->cus_name = new char[strlen(copy.cus_name) + 1];
	strcpy_s(this->cus_name, NAME_LEN, copy.cus_name);
}
Account Account::operator=(Account& copy) // ���� ������
{
	this->accID = copy.accID;
	this->remain_money = copy.remain_money;
	this->cus_name = new char[strlen(copy.cus_name) + 1];
	strcpy_s(this->cus_name, NAME_LEN, copy.cus_name);
}
int Account::return_ID() const { return accID; } //ID�� �����ϴ� ��� �Լ�
int Account::return_remain_money() const { return remain_money; } //�ݾ׿� �����ϴ� ��� �Լ�
char* Account::return_cusname() const { return cus_name; } //�̸��� �����ϴ� ��� �Լ�
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
	cout << "����ID: " << this->accID << endl;
	cout << "��  ��: " << this->cus_name << endl;
	cout << "��  ��: " << this->remain_money << endl << endl;
}
Account::~Account() //�Ҹ���
{
	delete[]cus_name;
	cout << "������ ���� �Ҹ�" << endl;
}