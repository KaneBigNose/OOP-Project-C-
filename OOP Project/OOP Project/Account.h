#pragma once

class Account //���� Ŭ����
{
private:
	int accID;
	int remain_money;
	char* cus_name;
public:
	Account() {}; // �⺻ ������
	Account(int accID, char* cus_name, int money); // �Ϲ� ������
	Account(const Account& copy); // ���� ������
	Account operator=(Account& copy); // ���� ������
	int return_ID() const; // ID�� �����ϴ� ��� �Լ�
	int return_remain_money() const; // �ݾ׿� �����ϴ� ��� �Լ�
	char* return_cusname() const; // �̸��� �����ϴ� ��� �Լ�
	virtual void DepositMoney(int money); // �Ա� ���� ��� �Լ�
	void WithDrawMoney(int money); // ��� ��� �Լ�
	void ShowInfo() const; // ������ ��Ÿ���� ��� �Լ�
	~Account(); // �Ҹ���
};