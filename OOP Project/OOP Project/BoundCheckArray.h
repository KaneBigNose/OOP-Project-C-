#pragma once

#include "Account.h"
#include "BankingCommonDec1.h"

typedef Account* Account_PTR; // Account의 포인터 형식의 별칭을 지정

template <class T>
class BoundCheckArray // Account 클래스의 포인터를 배열로 저장하는 클래스
{
private:
	Account_PTR* acc; // Account의 포인터를 저장하는 포인터
	int acc_len;
	BoundCheckArray(const BoundCheckArray& copy) : acc_len(copy.acc_len) { acc = NULL; } // 복사 생성자 방지
	BoundCheckArray operator=(const BoundCheckArray& copy) {} // 대입 연산자 방지
public:
	BoundCheckArray(); // 디폴트 생성자
	BoundCheckArray(int num); // 생성자
	Account_PTR& operator[](int num); // 연산자 []의 오버로딩
	Account_PTR operator[](int num) const; // 연산자 []의 오버로딩 const형
	~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray() : acc_len() // 디폴트 생성자
{
	acc = new Account_PTR; // Account의 포인터를 배열로 동적 할당함
}

template <class T>
BoundCheckArray<T>::BoundCheckArray(int num) : acc_len(num) // 생성자
{
	acc = new Account_PTR[num]; // Account의 포인터를 배열로 동적 할당함
}

template <class T>
Account_PTR& BoundCheckArray<T>::operator[](int num) // 연산자 []의 오버로딩
{
	if (num < 0 || num >= MAX_ACCOUNT)
	{
		cout << "에러 : 범위를 벗어난 값의 전달" << endl;
		exit(1);
	}
	return acc[num];
}

template <class T>
Account_PTR BoundCheckArray<T>::operator[](int num) const // 연산자 []의 오버로딩 const형
{
	if (num < 0 || num >= MAX_ACCOUNT)
	{
		cout << "에러 : 범위를 벗어난 값의 전달" << endl;
		exit(1);
	}
	return acc[num];
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]acc;
}