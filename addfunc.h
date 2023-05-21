// CRUD 외 부가기능 설정
/* 1. 회원가입
   2. 로그인
   3. 코딩 공부 정도 레벨로 파악
   4. 코딩공부 레벨에 따른 마일리지 지급 및 점수 출력
   5. 마일리지 내역 확인 
*/

#ifndef ADDFUNC_H
#define ADDFUNC_H

int registerUser(const char *username, const char *password); // 회원가입
int loginUser(const char *username, const char *password); // 로그인

void addTransaction(const char* description, int miles); // 마일리지 부여
void printTransactionHistory(); // 마일리지 점수 출력
void awardMiles(int codingLevel); // 코딩레벨에 따른 마일리지 제공

#endif /* ADDFUNC_H */

