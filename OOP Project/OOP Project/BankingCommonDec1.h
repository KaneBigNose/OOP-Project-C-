#pragma once
#include <iostream>
#include <cstring>
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreitAccount.h"
#include "AccountHandler.h"

using namespace std;

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; //�޴��� �ʿ��� ������ ����

namespace CREDIT_LEVEL // �ſ��޿� ���� �߰� ������
{
	enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
}