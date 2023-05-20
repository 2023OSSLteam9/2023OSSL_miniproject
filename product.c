#include "product.h"

// product.c 함수 기록

int selectMenu(){
    int menu;

    printf("*********** 함께 코딩해요 ***********\n");
    printf("1. 게시글 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("0. 종료\n");
    printf("************************************\n");
    scanf("%d", &menu);
    return menu;
}

int addContent(content *cp){
    printf("표기될 작성자의 이름을 입력해 주세요.\n");
    getchar();
    scanf("%[^\n]s", cp->writerName);
    printf("제목을 입력해 주세요.\n");
    getchar();
    scanf("%[^\n]s", cp->title);
    printf("내용을 입력해 주세요.\n");
    getchar();
    scanf("%[^\n]s", cp->contents);

    time_t now; 
    time(&now);
    struct tm *tm_info = localtime(&now);
    strftime(cp->writtenDate, sizeof(cp->writtenDate), "%Y-%m-%d %H:%M:%S", tm_info); // 게시글이 작성된 시각 가져오기

    return 1;
}

void listContent(content *cp[], int count){
    printf("번호   제목                 작성시각             작성자 \t(삭제 시 0번을 눌러 취소)\n");
    for (int i = 0; i < count; i++) {
        if (cp[i] == NULL) continue;
        printf("%-5d  %-20s %-20s %s\n", i + 1, cp[i]->title, cp[i]->writtenDate, cp[i]->writerName);
    }
}

void showContent(content *cp[], int count){
    int num;
    listContent(cp, count);
    scanf("%d", &num);
    printf("\n제목 : %s\t 작성자 %s\n\n", cp[num-1]->title, cp[num-1]->writerName);
    printf("%s\n", cp[num-1]->contents);
    printf("\nEnter를 눌러서 진행해주세요...");
    while(getchar() != '\n');        // 엔터를 누르기 전까지 메뉴로 돌아가지 않음
    getchar();                       // 입력 버퍼 제거
}

void modifyContent(content *cp[], int count){
    int num;
    listContent(cp, count);
    printf("몇 번을 수정 하시겠습니까?");
    scanf("%d", &num);

    printf("표기될 작성자의 이름을 입력해 주세요.\n");
    getchar();
    scanf("%[^\n]s", cp[num-1]->writerName);
    printf("제목을 입력해 주세요.\n");
    getchar();
    scanf("%[^\n]s", cp[num-1]->title);
    printf("내용을 입력해 주세요.\n");
    getchar();
    scanf("%[^\n]s", cp[num-1]->contents);

    time_t now; 
    time(&now);
    struct tm *tm_info = localtime(&now);
    strftime(cp[num-1]->writtenDate, sizeof(cp[num-1]->writtenDate), "%Y-%m-%d %H:%M:%S", tm_info); // 게시글이 작성된 시각 가져오기
}

int cancelContent(content *cp[], int count){
    int no;
    listContent(cp, count);
    printf("몇 번을 삭제 하시겠습니까?");
    scanf("%d", &no);
    return no;
}

void saveData(content *cp[], int count){
    FILE *fp;
    fp = fopen("boardContent.txt", "wt");

    for(int i = 0; i < count; i++){
        if(cp[i]->title == NULL) continue;
        fprintf(fp, "%s\n%s\n%s\n%s\n" , cp[i]->title, cp[i]->contents, cp[i]->writerName, cp[i]->writtenDate);
    }
    fclose(fp);
    printf("=> 성공적으로 저장하였습니다.\n");
}

int loadData(content *cp[]) {
    int count = 0, i = 0;
    FILE *fp;
    fp = fopen("boardContent.txt", "rt");
    
if (fp == NULL) {
    printf("불러올 파일이 존재하지 않습니다.\n");
    return 0;
}

while (count < 100) {
    cp[count] = (content *)malloc(sizeof(content));
    if (fscanf(fp, "%[^\n]%*c", cp[count]->title) == EOF)
        break; // 파일의 끝일 경우 break
    fscanf(fp, "%[^\n]%*c", cp[count]->contents);
    fscanf(fp, "%[^\n]%*c", cp[count]->writerName);
    fscanf(fp, "%[^\n]%*c", cp[count]->writtenDate);
    count++;
}
fclose(fp);
printf("=> 성공적으로 불러왔습니다.\n");
return count;
}