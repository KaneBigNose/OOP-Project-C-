#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

void ShowMenu(void);      
void MakeAccount(void);    
void DepositMoney(void);       
void WithdrawMoney(void);     
void ShowAllAccInfo(void);     

class Account
{
private:
	int accID;
	int remain_money;
	char* cus_name;
public:
	Account(int accID, char* cus_name, int money)
		:accID(accID), remain_money(money)
	{
		size_t length = strlen(cus_name);
		this->cus_name = new char[length + 1];
		strcpy_s(this->cus_name, NAME_LEN, cus_name);
	}
	int return_ID() const { return accID; }
	int return_remain_money() const { return remain_money; }
	char* return_cusname() const { return cus_name; }
	void DepositMoney(int money)
	{
		this->remain_money += money;
		cout << "�ԱݿϷ�" << endl << endl;
	}
	void WithDrawMoney(int money)
	{
		if (this->remain_money < money)
		{
			cout << "�ܾ׺���" << endl << endl;
			return;
		}

		this->remain_money -= money;
		cout << "��ݿϷ�" << endl << endl;
	}
	void ShowInfo() const
	{
		cout << "����ID: " << this->accID << endl;
		cout << "��  ��: " << this->cus_name << endl;
		cout << "��  ��: " << this->remain_money << endl << endl;
	}
	~Account() 
	{ 
		delete []cus_name;
		cout << "������ ���� �Ҹ�"; 
	}
};

Account* accArr[100];
int accNum = 0;

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� ���� ����" << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int money;
	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> money;
	cout << endl;
	accArr[accNum] = new Account(id, name, money);
	accNum++;

}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�Աݾ�: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->return_ID() == id)
		{
			accArr[i]->DepositMoney(money);
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��ݾ�: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->return_ID() == id)
		{
			accArr[i]->WithDrawMoney(money);
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowInfo();
	}
}