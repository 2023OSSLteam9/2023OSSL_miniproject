#include "product.h"
#include "addfunc.h"

int main(){
    int count = 0, index = 0, menu;
    content *cp[100];

    count = loadData(cp);
    index = count;

    while(1){
    menu = selectMenu();
    if(menu == 0){
        printf("���α׷��� �����մϴ�."); 
        break;
    }
    else if(menu == 2){
        cp[index] = (content *)malloc(sizeof(content));
        count += addContent(cp[index++]);
        }
    else if(menu == 1|| menu == 3 || menu == 4){        //  2�� �߰��� �����Ͱ� ���� ��� 1,3,4�� �ϸ� �ǵ��ư���
        if(count <= 0){
            printf("�����Ͱ� �������� �ʽ��ϴ�.\n"); continue;
        }
    }
    if(menu == 1) showContent(cp, index);
    else if(menu == 3) modifyContent(cp, index);
    else if(menu == 4){
    int num = cancelContent(cp, index);
                if (num == 0) {
                printf("=> ��� ��\n");
                continue;
            }
        free(cp[num-1]);
        cp[num-1] = NULL;
        count--;
        printf("\n���������� �����Ͽ����ϴ�.\n");
        }
    else if(menu == 5){
        saveData(cp, index);
    }
    
}
}
