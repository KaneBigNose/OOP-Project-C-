#pragma once

#include "AccountArray.h"
#include "BankingCommonDec1.h"

AccountArray::AccountArray() : acc_len() // 디폴트 생성자
{
	acc = new Account_PTR; // Account의 포인터를 배열로 동적 할당함
}
AccountArray::AccountArray(int num) : acc_len(num) // 생성자
{
	acc = new Account_PTR[num]; // Account의 포인터를 배열로 동적 할당함
}
Account_PTR& AccountArray::operator[](int num) // 연산자 []의 오버로딩
{
	if (num < 0 || num >= MAX_ACCOUNT)
	{
		cout << "에러 : 범위를 벗어난 값의 전달" << endl;
		exit(1);
	}
	return acc[num];
}
Account_PTR AccountArray::operator[](int num) const // 연산자 []의 오버로딩 const형
{
	if (num < 0 || num >= MAX_ACCOUNT)
	{
		cout << "에러 : 범위를 벗어난 값의 전달" << endl;
		exit(1);
	}
	return acc[num];
}
AccountArray::~AccountArray()
{
	delete []acc;
}