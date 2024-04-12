#pragma once

#include <iostream>
#include <cstring>
using namespace std;

class String // String 클래스
{
private:
	char* str;
	int str_len;
public:
	String(); // 디폴트 생성자
	String(const char* s); // 기본 생성자
	String(char* s); // 기본 생성자
	String(const String& s); // 복사 생성자
	~String(); // 소멸자

	String& operator= (const String& s); // = 연산자 오버로딩
	String& operator+= (const String& s); // += 연산자 오버로딩
	bool operator== (const String& s); // == 연산자 오버로딩
	String operator+ (const String& s); // + 연산자 오버로딩

	friend ostream& operator<<(ostream& os, const String& s); // << 연산자 오버로딩
	friend istream& operator>>(istream& is, String& s); // >> 연산자 오버로딩

	void SetStr(char* c); // str의 값을 설정하는 멤버 함수
	char* GetStr() const;
};