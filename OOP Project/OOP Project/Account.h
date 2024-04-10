#pragma once 

#include "String.h"

class Account //계좌 클래스
{
private:
	int accID;
	int remain_money;
	String cus_name;
public:
	Account() : accID(0), remain_money(0) {} // 디폴트 생성자
	Account(int accID, String cus_name, int money); // 일반 생성자

	int Get_ID() const { return accID; } //ID에 접근하는 멤버 함수
	int Get_remain_money() const { return remain_money; } //금액에 접근하는 멤버 함수
	String Get_cusname() const { return cus_name; } //이름에 접근하는 멤버 함수

	virtual void DepositMoney(int money); // 입금 가상 멤버 함수
	void WithDrawMoney(int money); // 출금 멤버 함수
	void ShowInfo() const; // 정보를 나타내는 멤버 함수
	virtual int GetInterestRate() const; // 이자율을 반환하는 함수
};