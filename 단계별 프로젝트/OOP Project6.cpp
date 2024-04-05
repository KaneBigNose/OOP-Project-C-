#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; //메뉴에 필요한 열거형 선언

class Account //계좌 클래스
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
	virtual void DepositMoney(int money) //입금 가상 멤버 함수
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
		cout << "생성된 계좌 소멸" << endl;
	}
};

class NormalAccount : public Account // 보통 예금 계좌 클래스
{
private:
	int interest_rate; // 이자율
public:
	NormalAccount(int accID, char* cus_name, int money, int interest_rate)
		: Account(accID, cus_name, money), interest_rate(interest_rate) {}
	virtual void DepositMoney(int money) // 입금 시 이자를 추가로 지급하는 형식의 가상 멤버 함수
	{
		Account::DepositMoney(money);
		AddInterestMoney();
	}
	void AddInterestMoney() // 이자를 더하는 멤버 함수
	{
		Account::DepositMoney((int)(return_remain_money() * interest_rate / 100.0));
	}
	int GetInterestRate() const
	{
		return interest_rate;
	}
};

namespace CREDIT_LEVEL // 신용등급에 따른 추가 이자율
{
	enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
}

class HighCreditAccount : public NormalAccount // 신용 신뢰 계좌 클래스
{
private:
	int credit_level; // 신용 등급
public:
	HighCreditAccount(int accID, char* cus_name, int money, double interest_rate, int credit_level)
		: NormalAccount(accID, cus_name, money, interest_rate + credit_level), credit_level(credit_level) {}
};

class AccountHandler //계좌 컨트롤 클래스
{
private:
	Account* accArr[100]; //객체 배열
	int accNum; //생성된 계좌의 개수
public:
	AccountHandler() : accNum(0) {} //생성자
	void ShowMenu() const //메뉴 나타내기 멤버 함수
	{
		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입    금" << endl;
		cout << "3. 출    금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
	}
	void ChoiceHowToMakeAccount(int choice) // 생성할 계좌 유형 설정 멤버 함수
	{
		cout << "[계좌종류선택]" << endl;
		cout << "1. 보통예금계좌   2. 신용신뢰계좌" << endl;
		cout << "선택 : "; cin >> choice;
		switch (choice)
		{
		case 1:
			MakeNormalAccount();
			break;
		case 2:
			MakeHighCreditAccount();
			break;
		default:
			cout << "잘못된 값을 입력하였습니다." << endl;
			break;
		}
	}
	void MakeNormalAccount() // 보통 예금 계좌 개설 멤버 함수
	{
		int id;
		char name[NAME_LEN];
		int money;
		int interest_rate;
		cout << "[보통예금계좌 개설]" << endl;
		cout << "계좌ID: ";	cin >> id;
		cout << "이  름: ";	cin >> name;
		cout << "입금액: ";	cin >> money;
		cout << "이자율: "; cin >> interest_rate;
		cout << endl;
		accArr[accNum] = new NormalAccount(id, name, money, interest_rate);
		accNum++;
	}
	void MakeHighCreditAccount() // 신용 신뢰 계좌 개설 멤버 함수
	{
		int id;
		char name[NAME_LEN];
		int money;
		int interest_rate;
		int credit_level;
		cout << "[신용신뢰계좌 개설]" << endl;
		cout << "계좌ID: ";	cin >> id;
		cout << "이  름: ";	cin >> name;
		cout << "입금액: ";	cin >> money;
		cout << "이자율: "; cin >> interest_rate;
		cout << "신용등급(1 to A, 2 to B, 3 to C): "; cin >> credit_level;
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
			cout << "잘못된 값을 입력하였습니다." << endl;
			break;
		}
	}
	void DepositMoney() //입금 멤버 함수
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
	void WithdrawMoney() //출금 멤버 함수
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
	void ShowAllAccInfo() const //정보 제공 멤버 함수
	{
		for (int i = 0; i < accNum; i++)
		{
			accArr[i]->ShowInfo();
		}
	}
	~AccountHandler() //소멸자
	{
		for (int i = 0; i < accNum; i++) { delete accArr[i]; } //생성된 계좌들 하나씩 소멸
		cout << "컨트롤 객체 소멸" << endl;
	}
};

int main(void) //메인 함수
{
	AccountHandler acchad;
	int choice; //사용자로부터 입력받은 번호

	while (1)
	{
		acchad.ShowMenu();
		cout << "선택: ";
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
		default: //1~5가 아닌 다른 값을 입력했을 경우
			cout << "잘못된 값을 전달" << endl;
		}
	}
	return 0;
}