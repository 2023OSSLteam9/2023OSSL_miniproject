// CRUD 외 부가기능 설정
/* 1. C언어로 로그인/회원가입 페이지 구현
   2. 마일리지 제공 및 마일리지 별 레벨 설명 가이드라인 필요
   3. 게시물 업로드 기능
   4. 댓글 추가 기능
   
-> 어떤 함수를 구현할지 결정!!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "addfunc.h"

int main() {
    registerUser("user1", "password1"); // 회원가입
    registerUser("user2", "password2");

    loginUser("user1", "password1"); //로그인 
    loginUser("user1", "password2");
    loginUser("user2", "password1");

    return 0;
}
