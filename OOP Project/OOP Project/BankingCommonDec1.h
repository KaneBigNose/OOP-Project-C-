#pragma once // �ߺ�����

#include <iostream> // �⺻ ���̺귯��
#include <cstring>

#include "Account.h" // ��� ����
#include "NormalAccount.h"
#include "HighCreitAccount.h"
#include "AccountHandler.h"
#include "AccountArray.h"

using namespace std;

const int NAME_LEN = 20;
const int MAX_ACCOUNT = 100;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; //�޴��� �ʿ��� ������ ����

namespace CREDIT_LEVEL // �ſ��޿� ���� �߰� ������
{
	enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
}