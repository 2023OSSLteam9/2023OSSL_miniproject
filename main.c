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
        printf("프로그램을 종료합니다."); 
        break;
    }
    else if(menu == 2){
        cp[index] = (content *)malloc(sizeof(content));
        count += addContent(cp[index++]);
        }
    else if(menu == 1|| menu == 3 || menu == 4){        //  2로 추가된 데이터가 없을 경우 1,3,4를 하면 되돌아가기
        if(count <= 0){
            printf("데이터가 존재하지 않습니다.\n"); continue;
        }
    }
    if(menu == 1) showContent(cp, index);
    else if(menu == 3) modifyContent(cp, index);
    else if(menu == 4){
    int num = cancelContent(cp, index);
                if (num == 0) {
                printf("=> 취소 됨\n");
                continue;
            }
        free(cp[num-1]);
        cp[num-1] = NULL;
        count--;
        printf("\n성공적으로 제거하였습니다.\n");
        }
    else if(menu == 5){
        saveData(cp, index);
    }
    
}
}
