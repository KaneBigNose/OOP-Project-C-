#pragma once 

#include "BankingCommonDec1.h"

class Account //계좌 클래스
{
private:
	int accID;
	int remain_money;
	char* cus_name;
public:
	Account() : accID(0), remain_money(0), cus_name(0) {}; // 기본 생성자
	Account(int accID, char* cus_name, int money); // 일반 생성자
	Account(const Account& copy); // 복사 생성자
	Account& operator=(Account& copy); // 대입 연산자
	int return_ID() const; // ID에 접근하는 멤버 함수
	int return_remain_money() const; // 금액에 접근하는 멤버 함수
	char* return_cusname() const; // 이름에 접근하는 멤버 함수
	virtual void DepositMoney(int money); // 입금 가상 멤버 함수
	void WithDrawMoney(int money); // 출금 멤버 함수
	void ShowInfo() const; // 정보를 나타내는 멤버 함수
	virtual int GetInterestRate() const;
	~Account(); // 소멸자
};