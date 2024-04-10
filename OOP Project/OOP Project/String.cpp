#pragma once

#include "String.h"
#include "BankingCommonDec1.h"

String::String()
{
	str_len = 0;
	str = NULL;
}

String::String(const char* s)
{
	str_len = (int)(strlen(s) + 1);
	str = new char[str_len + 1];
	strcpy_s(str, NAME_LEN, s);
}

String::String(const String& s)
{
	str_len = s.str_len + 1;
	str = new char[str_len + 1];
	strcpy_s(str, NAME_LEN, s.str);
}

String::~String()
{
	if (str != NULL)
		delete[]str;
}

String& String::operator= (const String& s)
{
	if (str != NULL)
		delete[]str;
	str_len = s.str_len + 1;
	str = new char[str_len+1];
	strcpy_s(str, NAME_LEN, s.str);
	if (str != NULL)
		delete[]str;
	return *this;
}

String& String::operator+= (const String& s)
{
	if (str != NULL)
		delete[]str;
	str_len += (s.str_len + 1);
	char* tempstr = new char[str_len+1];
	strcpy_s(tempstr, NAME_LEN, str);
	strcat_s(tempstr, NAME_LEN, s.str);
	str = tempstr;
	return *this;
}

bool String::operator== (const String& s)
{
	if (str == s.str) { return true; }
	else { return false; }
}

String String::operator+ (const String& s)
{
	char* tempstr = new char[str_len + s.str_len + 1];
	strcpy_s(tempstr, NAME_LEN, str);
	strcat_s(tempstr, NAME_LEN, s.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}

ostream& operator<< (ostream& os, const String& s)
{
	cout << s.str;
	return os;
}

istream& operator>> (istream& is, String& s)
{
	char* temp;
	temp = new char[NAME_LEN];
	cin >> temp;
	String tempstr(temp);
	s = tempstr;
	delete[]temp;
	return is;
}