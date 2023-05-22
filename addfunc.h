// CRUD 외 부가기능 설정
/* 1. 회원가입
   2. 로그인
   3. 코딩 공부 정도 레벨로 파악
   4. 코딩공부 레벨에 따른 마일리지 지급 및 점수 출력
   5. 마일리지 내역 확인 
*/

#ifndef ADDFUNC_H
#define ADDFUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_TRANSACTIONS 100

int registerUser(const char *username, const char *password); // 회원가입
int loginUser(const char *username, const char *password); // 로그인

void addTransaction(const char* description, int miles); // 마일리지 제공
void printTransactionHistory(); //마일리지 내역 출력
void awardMiles(int codingLevel); // 입력된 레벨에 따른 마일리지 지급

#endif /* ADDFUNC_H */

