#include "product.h"

// product.c �Լ� ���

int selectMenu(){
    int menu;

    printf("*********** �Բ� �ڵ��ؿ� ***********\n");
    printf("1. �Խñ� ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ����\n");
    printf("0. ����\n");
    printf("************************************\n");
    scanf("%d", &menu);
    return menu;
}

int addContent(content *cp){
    printf("ǥ��� �ۼ����� �̸��� �Է��� �ּ���.\n");
    getchar();
    scanf("%[^\n]s", cp->writerName);
    printf("������ �Է��� �ּ���.\n");
    getchar();
    scanf("%[^\n]s", cp->title);
    printf("������ �Է��� �ּ���.\n");
    getchar();
    scanf("%[^\n]s", cp->contents);

    time_t now; 
    time(&now);
    struct tm *tm_info = localtime(&now);
    strftime(cp->writtenDate, sizeof(cp->writtenDate), "%Y-%m-%d %H:%M:%S", tm_info); // �Խñ��� �ۼ��� �ð� ��������

    return 1;
}

void listContent(content *cp[], int count){
    printf("��ȣ   ����                 �ۼ��ð�             �ۼ��� \t(���� �� 0���� ���� ���)\n");
    for (int i = 0; i < count; i++) {
        if (cp[i] == NULL) continue;
        printf("%-5d  %-20s %-20s %s\n", i + 1, cp[i]->title, cp[i]->writtenDate, cp[i]->writerName);
    }
}

void showContent(content *cp[], int count){
    int num;
    listContent(cp, count);
    scanf("%d", &num);
    printf("\n���� : %s\t �ۼ��� %s\n\n", cp[num-1]->title, cp[num-1]->writerName);
    printf("%s\n", cp[num-1]->contents);
    printf("\nEnter�� ������ �������ּ���...");
    while(getchar() != '\n');        // ���͸� ������ ������ �޴��� ���ư��� ����
    getchar();                       // �Է� ���� ����
}

void modifyContent(content *cp[], int count){
    int num;
    listContent(cp, count);
    printf("�� ���� ���� �Ͻðڽ��ϱ�?");
    scanf("%d", &num);

    printf("ǥ��� �ۼ����� �̸��� �Է��� �ּ���.\n");
    getchar();
    scanf("%[^\n]s", cp[num-1]->writerName);
    printf("������ �Է��� �ּ���.\n");
    getchar();
    scanf("%[^\n]s", cp[num-1]->title);
    printf("������ �Է��� �ּ���.\n");
    getchar();
    scanf("%[^\n]s", cp[num-1]->contents);

    time_t now; 
    time(&now);
    struct tm *tm_info = localtime(&now);
    strftime(cp[num-1]->writtenDate, sizeof(cp[num-1]->writtenDate), "%Y-%m-%d %H:%M:%S", tm_info); // �Խñ��� �ۼ��� �ð� ��������
}

int cancelContent(content *cp[], int count){
    int no;
    listContent(cp, count);
    printf("�� ���� ���� �Ͻðڽ��ϱ�?");
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
    printf("=> ���������� �����Ͽ����ϴ�.\n");
}

int loadData(content *cp[]) {
    int count = 0, i = 0;
    FILE *fp;
    fp = fopen("boardContent.txt", "rt");
    
if (fp == NULL) {
    printf("�ҷ��� ������ �������� �ʽ��ϴ�.\n");
    return 0;
}

while (count < 100) {
    cp[count] = (content *)malloc(sizeof(content));
    if (fscanf(fp, "%[^\n]%*c", cp[count]->title) == EOF)
        break; // ������ ���� ��� break
    fscanf(fp, "%[^\n]%*c", cp[count]->contents);
    fscanf(fp, "%[^\n]%*c", cp[count]->writerName);
    fscanf(fp, "%[^\n]%*c", cp[count]->writtenDate);
    count++;
}
fclose(fp);
printf("=> ���������� �ҷ��Խ��ϴ�.\n");
return count;
}