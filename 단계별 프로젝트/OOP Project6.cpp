#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; //�޴��� �ʿ��� ������ ����

class Account //���� Ŭ����
{
private:
	int accID;
	int remain_money;
	char* cus_name;
public:
	Account(int accID, char* cus_name, int money) //�Ϲ� ������
		:accID(accID), remain_money(money)
	{
		this->cus_name = new char[strlen(cus_name) + 1];
		strcpy_s(this->cus_name, NAME_LEN, cus_name);
	}
	Account(const Account& copy) //���� ������
		:accID(copy.accID), remain_money(copy.remain_money)
	{
		this->cus_name = new char[strlen(copy.cus_name) + 1];
		strcpy_s(this->cus_name, NAME_LEN, copy.cus_name);
	}
	int return_ID() const { return accID; } //ID�� �����ϴ� ��� �Լ�
	int return_remain_money() const { return remain_money; } //�ݾ׿� �����ϴ� ��� �Լ�
	char* return_cusname() const { return cus_name; } //�̸��� �����ϴ� ��� �Լ�
	virtual void DepositMoney(int money) //�Ա� ���� ��� �Լ�
	{
		this->remain_money += money;
		cout << "�ԱݿϷ�" << endl << endl;
	}
	void WithDrawMoney(int money) //��� ��� �Լ�
	{
		if (this->remain_money < money)
		{
			cout << "�ܾ׺���" << endl << endl;
			return;
		}

		this->remain_money -= money;
		cout << "��ݿϷ�" << endl << endl;
	}
	void ShowInfo() const //������ ��Ÿ���� ��� �Լ�
	{
		cout << "����ID: " << this->accID << endl;
		cout << "��  ��: " << this->cus_name << endl;
		cout << "��  ��: " << this->remain_money << endl << endl;
	}
	~Account() //�Ҹ���
	{
		delete[]cus_name;
		cout << "������ ���� �Ҹ�" << endl;
	}
};

class NormalAccount : public Account // ���� ���� ���� Ŭ����
{
private:
	int interest_rate; // ������
public:
	NormalAccount(int accID, char* cus_name, int money, int interest_rate)
		: Account(accID, cus_name, money), interest_rate(interest_rate) {}
	virtual void DepositMoney(int money) // �Ա� �� ���ڸ� �߰��� �����ϴ� ������ ���� ��� �Լ�
	{
		Account::DepositMoney(money);
		AddInterestMoney();
	}
	void AddInterestMoney() // ���ڸ� ���ϴ� ��� �Լ�
	{
		Account::DepositMoney((int)(return_remain_money() * interest_rate / 100.0));
	}
	int GetInterestRate() const
	{
		return interest_rate;
	}
};

namespace CREDIT_LEVEL // �ſ��޿� ���� �߰� ������
{
	enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
}

class HighCreditAccount : public NormalAccount // �ſ� �ŷ� ���� Ŭ����
{
private:
	int credit_level; // �ſ� ���
public:
	HighCreditAccount(int accID, char* cus_name, int money, double interest_rate, int credit_level)
		: NormalAccount(accID, cus_name, money, interest_rate + credit_level), credit_level(credit_level) {}
};

class AccountHandler //���� ��Ʈ�� Ŭ����
{
private:
	Account* accArr[100]; //��ü �迭
	int accNum; //������ ������ ����
public:
	AccountHandler() : accNum(0) {} //������
	void ShowMenu() const //�޴� ��Ÿ���� ��� �Լ�
	{
		cout << "-----Menu------" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. ��    ��" << endl;
		cout << "3. ��    ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
	}
	void ChoiceHowToMakeAccount(int choice) // ������ ���� ���� ���� ��� �Լ�
	{
		cout << "[������������]" << endl;
		cout << "1. ���뿹�ݰ���   2. �ſ�ŷڰ���" << endl;
		cout << "���� : "; cin >> choice;
		switch (choice)
		{
		case 1:
			MakeNormalAccount();
			break;
		case 2:
			MakeHighCreditAccount();
			break;
		default:
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			break;
		}
	}
	void MakeNormalAccount() // ���� ���� ���� ���� ��� �Լ�
	{
		int id;
		char name[NAME_LEN];
		int money;
		int interest_rate;
		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "����ID: ";	cin >> id;
		cout << "��  ��: ";	cin >> name;
		cout << "�Աݾ�: ";	cin >> money;
		cout << "������: "; cin >> interest_rate;
		cout << endl;
		accArr[accNum] = new NormalAccount(id, name, money, interest_rate);
		accNum++;
	}
	void MakeHighCreditAccount() // �ſ� �ŷ� ���� ���� ��� �Լ�
	{
		int id;
		char name[NAME_LEN];
		int money;
		int interest_rate;
		int credit_level;
		cout << "[�ſ�ŷڰ��� ����]" << endl;
		cout << "����ID: ";	cin >> id;
		cout << "��  ��: ";	cin >> name;
		cout << "�Աݾ�: ";	cin >> money;
		cout << "������: "; cin >> interest_rate;
		cout << "�ſ���(1 to A, 2 to B, 3 to C): "; cin >> credit_level;
		cout << endl;
		switch (credit_level)
		{
		case 1:
			accArr[accNum] = new HighCreditAccount(id, name, money, interest_rate, CREDIT_LEVEL::LEVEL_A);
			accNum++;
			break;
		case 2:
			accArr[accNum] = new HighCreditAccount(id, name, money, interest_rate, CREDIT_LEVEL::LEVEL_B);
			accNum++;
			break;
		case 3:
			accArr[accNum] = new HighCreditAccount(id, name, money, interest_rate, CREDIT_LEVEL::LEVEL_C);
			accNum++;
			break;
		default:
			cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
			break;
		}
	}
	void DepositMoney() //�Ա� ��� �Լ�
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
	void WithdrawMoney() //��� ��� �Լ�
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
	void ShowAllAccInfo() const //���� ���� ��� �Լ�
	{
		for (int i = 0; i < accNum; i++)
		{
			accArr[i]->ShowInfo();
		}
	}
	~AccountHandler() //�Ҹ���
	{
		for (int i = 0; i < accNum; i++) { delete accArr[i]; } //������ ���µ� �ϳ��� �Ҹ�
		cout << "��Ʈ�� ��ü �Ҹ�" << endl;
	}
};

int main(void) //���� �Լ�
{
	AccountHandler acchad;
	int choice; //����ڷκ��� �Է¹��� ��ȣ

	while (1)
	{
		acchad.ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			acchad.ChoiceHowToMakeAccount(choice);
			break;
		case DEPOSIT:
			acchad.DepositMoney();
			break;
		case WITHDRAW:
			acchad.WithdrawMoney();
			break;
		case INQUIRE:
			acchad.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default: //1~5�� �ƴ� �ٸ� ���� �Է����� ���
			cout << "�߸��� ���� ����" << endl;
		}
	}
	return 0;
}