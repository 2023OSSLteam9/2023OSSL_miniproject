#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//CRUD 구현

typedef struct boardContent{
    char title[100];             // 게시글 제목
    char contents[500];          // 게시글 내용
    char writerName[50];        // 글쓴이 이름
    char writtenDate[20];       // 작성된 시간
} content;

int selectMenu(); // 메뉴 선택 함수
int addContent(); // 게시글 추가 함수
void showContent(); // 추가된 게시글 호출 함수
void listContent(); // 추가된 게시글의 내용 호출 함수
void modifyContent(); // 게시글 수정 함수
int cancelContent(); // 게시글 삭제 함수
void saveData(); // 저장 함수
int loadData(); // 불러오기 함수
