#pragma once // 중복방지

#include <iostream> // 기본 라이브러리
#include <cstring>

#include "Account.h" // 헤더 파일
#include "NormalAccount.h"
#include "HighCreitAccount.h"
#include "AccountHandler.h"
#include "AccountArray.h"

using namespace std;

const int NAME_LEN = 20;
const int MAX_ACCOUNT = 100;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; //메뉴에 필요한 열거형 선언

namespace CREDIT_LEVEL // 신용등급에 따른 추가 이자율
{
	enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
}