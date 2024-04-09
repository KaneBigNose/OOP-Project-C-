#pragma once

#include "BankingCommonDec1.h"

class AccountHandler // 계좌 컨트롤 클래스
{
private:
	AccountArray accArr; // 객체 배열
	int accNum; // 생성된 계좌의 개수
public:
	AccountHandler(); // 생성자
	void ShowMenu() const; // 메뉴 나타내기 멤버 함수
	void ChoiceHowToMakeAccount(int choice); // 생성할 계좌 유형 설정 멤버 함수
	void MakeNormalAccount(); // 보통 예금 계좌 개설 멤버 함수
	void MakeHighCreditAccount(); // 신용 신뢰 계좌 개설 멤버 함수
	void DepositMoney(); // 입금 멤버 함수
	void WithdrawMoney(); // 출금 멤버 함수
	void ShowAllAccInfo() const; // 정보 제공 멤버 함수
	~AccountHandler(); // 소멸자
};