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
		cout << "입금완료" << endl << endl;
	}
	void WithDrawMoney(int money)
	{
		if (this->remain_money < money)
		{
			cout << "잔액부족" << endl << endl;
			return;
		}

		this->remain_money -= money;
		cout << "출금완료" << endl << endl;
	}
	void ShowInfo() const
	{
		cout << "계좌ID: " << this->accID << endl;
		cout << "이  름: " << this->cus_name << endl;
		cout << "잔  액: " << this->remain_money << endl << endl;
	}
	~Account() 
	{ 
		delete []cus_name;
		cout << "생성된 계좌 소멸"; 
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
		cout << "선택: ";
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
			cout << "잘못된 값을 전달" << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int money;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> money;
	cout << endl;
	accArr[accNum] = new Account(id, name, money);
	accNum++;

}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[입    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->return_ID() == id)
		{
			accArr[i]->DepositMoney(money);
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->return_ID() == id)
		{
			accArr[i]->WithDrawMoney(money);
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowInfo();
	}
}