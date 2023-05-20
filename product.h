#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//CRUD ����

typedef struct boardContent{
    char title[100];             // �Խñ� ����
    char contents[500];          // �Խñ� ����
    char writerName[50];        // �۾��� �̸�
    char writtenDate[20];       // �ۼ��� �ð�
} content;

int selectMenu(); // �޴� ���� �Լ�
int addContent(); // �Խñ� �߰� �Լ�
void showContent(); // �߰��� �Խñ� ȣ�� �Լ�
void listContent(); // �߰��� �Խñ��� ���� ȣ�� �Լ�
void modifyContent(); // �Խñ� ���� �Լ�
int cancelContent(); // �Խñ� ���� �Լ�
void saveData(); // ���� �Լ�
int loadData();
