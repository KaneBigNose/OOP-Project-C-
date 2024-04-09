#pragma once

#include "BankingCommonDec1.h"

typedef Account* Account_PTR; // Account의 포인터 형식의 별칭을 지정

class AccountArray // Account 클래스의 포인터를 배열로 저장하는 클래스
{
private:
	Account_PTR* acc; // Account의 포인터를 저장하는 포인터
	int acc_len;
	AccountArray(const AccountArray& copy) {} // 복사 생성자 방지
	AccountArray operator=(const AccountArray& copy) {} // 대입 연산자 방지
public:
	AccountArray() {} // 디폴트 생성자
	AccountArray(int num); // 생성자
	Account_PTR& operator[](int num); // 연산자 []의 오버로딩
	Account_PTR operator[](int num) const; // 연산자 []의 오버로딩 const형
	~AccountArray();
};