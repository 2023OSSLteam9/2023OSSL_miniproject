#include "product.h"
#include "addfunc.h"

// product.c 함수 기록

int selectMenu(){
    int menu;

    printf("*********** Honor Code ***********\n");
    printf("1. View boards\n");
    printf("2. Add\n");
    printf("3. Modify\n");
    printf("4. Delete\n");
    printf("5. Save\n");
    printf("6. Assign Mileage\n");
    printf("7. History\n");
    printf("0. Quit\n");
    printf("************************************\n");
    scanf("%d", &menu);
    return menu;
}

int addContent(content *cp){
    printf("Please enter the name of the author to be displayed.\n");
    getchar();
    scanf("%[^\n]s", cp->writerName);
    printf("Please enter the title.\n");
    getchar();
    scanf("%[^\n]s", cp->title);
    printf("Please enter the content.\n");
    getchar();
    scanf("%[^\n]s", cp->contents);

    time_t now; 
    time(&now);
    struct tm *tm_info = localtime(&now);
    strftime(cp->writtenDate, sizeof(cp->writtenDate), "%Y-%m-%d %H:%M:%S", tm_info); // 게시글이 작성된 시각 가져오기

    return 1;
}

void listContent(content *cp[], int count){
    printf("No   Title                 Written Time             Author \t(Press 0 to quit Deletion.)\n");
    for (int i = 0; i < count; i++) {
        if (cp[i] == NULL) continue;
        printf("%-5d  %-20s %-20s %s\n", i + 1, cp[i]->title, cp[i]->writtenDate, cp[i]->writerName);
    }
}

void showContent(content *cp[], int count){
    int num;
    listContent(cp, count);
    scanf("%d", &num);
    printf("\nTitle : %s\t Author %s\n\n", cp[num-1]->title, cp[num-1]->writerName);
    printf("%s\n", cp[num-1]->contents);
    printf("\nPress Enter to continue...");
    while(getchar() != '\n');        // 엔터를 누르기 전까지 메뉴로 돌아가지 않음
    getchar();                       // 입력 버퍼 제거
}

void modifyContent(content *cp[], int count){
    int num;
    listContent(cp, count);
    printf("Which No would you like to modify?");
    scanf("%d", &num);

    printf("Please enter the name of the author to be displayed.\n");
    getchar();
    scanf("%[^\n]s", cp[num-1]->writerName);
    printf("Please enter the title.\n");
    getchar();
    scanf("%[^\n]s", cp[num-1]->title);
    printf("Please enter the content.\n");
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
    printf("Which No would you like to delete?");
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
    printf("=> Saved Successfully.\n");
}

int loadData(content *cp[]) {
    int count = 0, i = 0;
    FILE *fp;
    fp = fopen("boardContent.txt", "rt");
    
if (fp == NULL) {
    printf("There is no data for loading.\n");
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
printf("=> Loaded Successfully.\n");
return count;
}