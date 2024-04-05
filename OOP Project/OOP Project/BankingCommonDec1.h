#pragma once
#include <iostream>
#include <cstring>
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreitAccount.h"
#include "AccountHandler.h"

using namespace std;

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; //메뉴에 필요한 열거형 선언

namespace CREDIT_LEVEL // 신용등급에 따른 추가 이자율
{
	enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
}