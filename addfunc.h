// CRUD 외 부가기능 설정
/* 1. C언어로 로그인/회원가입 페이지 구현
   2. 마일리지 제공 및 마일리지 별 레벨 설명 가이드라인 필요
   3. 게시물 업로드 기능
   4. 댓글 추가 기능
   
-> 어떤 함수를 구현할지 결정!!
*/

#ifndef ADDFUNC_H
#define ADDFUNC_H

int registerUser(const char *username, const char *password); // 회원가입
int loginUser(const char *username, const char *password); // 로그인

void addTransaction(const char* description, int miles); // 마일리지 부여
void printTransactionHistory(); // 마일리지 점수 출력
void awardMiles(int codingLevel); // 코딩레벨에 따른 마일리지 제공

#endif /* ADDFUNC_H */

