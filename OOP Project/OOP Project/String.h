#pragma once

#include <iostream>
#include <cstring>
using namespace std;

class String // String Ŭ����
{
private:
	char* str;
	int str_len;
public:
	String(); // ����Ʈ ������
	String(const char* s); // �⺻ ������
	String(char* s); // �⺻ ������
	String(const String& s); // ���� ������
	~String(); // �Ҹ���

	String& operator= (const String& s); // = ������ �����ε�
	String& operator+= (const String& s); // += ������ �����ε�
	bool operator== (const String& s); // == ������ �����ε�
	String operator+ (const String& s); // + ������ �����ε�

	friend ostream& operator<<(ostream& os, const String& s); // << ������ �����ε�
	friend istream& operator>>(istream& is, String& s); // >> ������ �����ε�

	void SetStr(char* c); // str�� ���� �����ϴ� ��� �Լ�
	char* GetStr() const;
};