#pragma once

#include "BoundCheckArray.h"
#include "Exception.h"

class AccountHandler // ���� ��Ʈ�� Ŭ����
{
private:
	BoundCheckArray<Account*> accArr; // ��ü �迭
	int accNum; // ������ ������ ����
public:
	AccountHandler(); // ������
	void ShowMenu() const; // �޴� ��Ÿ���� ��� �Լ�
	void ChoiceHowToMakeAccount(int choice); // ������ ���� ���� ���� ��� �Լ�
	void MakeNormalAccount(); // ���� ���� ���� ���� ��� �Լ�
	void MakeHighCreditAccount(); // �ſ� �ŷ� ���� ���� ��� �Լ�
	void DepositMoney(); // �Ա� ��� �Լ�
	void WithdrawMoney(); // ��� ��� �Լ�
	void ShowAllAccInfo() const; // ���� ���� ��� �Լ�
	~AccountHandler(); // �Ҹ���
};