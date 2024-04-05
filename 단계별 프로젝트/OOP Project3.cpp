#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20; //글자 길이수 제한

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; //메뉴에 필요한 열거형 선언

void ShowMenu(void); //주요 함수 선언
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
	Account(int accID, char* cus_name, int money) //일반 생성자
		:accID(accID), remain_money(money)
	{
		this->cus_name = new char[strlen(cus_name) + 1];
		strcpy_s(this->cus_name, NAME_LEN, cus_name);
	}
	Account(const Account& copy) //복사 생성자
		:accID(copy.accID), remain_money(copy.remain_money)
	{
		this->cus_name = new char[strlen(copy.cus_name) + 1];
		strcpy_s(this->cus_name, NAME_LEN, copy.cus_name);
	}
	int return_ID() const { return accID; } //ID에 접근하는 멤버 함수
	int return_remain_money() const { return remain_money; } //금액에 접근하는 멤버 함수
	char* return_cusname() const { return cus_name; } //이름에 접근하는 멤버 함수
	void DepositMoney(int money) //입금 멤버 함수
	{
		this->remain_money += money;
		cout << "입금완료" << endl << endl;
	}
	void WithDrawMoney(int money) //출금 멤버 함수
	{
		if (this->remain_money < money)
		{
			cout << "잔액부족" << endl << endl;
			return;
		}

		this->remain_money -= money;
		cout << "출금완료" << endl << endl;
	}
	void ShowInfo() const //정보를 나타내는 멤버 함수
	{
		cout << "계좌ID: " << this->accID << endl;
		cout << "이  름: " << this->cus_name << endl;
		cout << "잔  액: " << this->remain_money << endl << endl;
	}
	~Account() //소멸자
	{
		delete[]cus_name;
		cout << "생성된 계좌 소멸";
	}
};

Account* accArr[100]; //객체 배열

int accNum = 0; //생성된 계좌의 개수

int main(void)
{
	int choice; //사용자로부터 입력받은 번호

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
		default: //1~5가 아닌 다른 값을 입력했을 경우
			cout << "잘못된 값을 전달" << endl;
		}
	}
	return 0;
}

void ShowMenu(void) //기본 세팅 함수
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void) //계좌 개설 함수
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

void DepositMoney(void) //입금 함수
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

void WithdrawMoney(void) //출금 함수
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

void ShowAllAccInfo(void) //정보 제공 함수
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowInfo();
	}
}