#include <stdio.h>

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
 char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome!\n");

    int loggedIn = 0;
    while (!loggedIn) {
        int choice;
        printf("6. Register\n");
        printf("7. Login\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 6:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                registerUser(username, password);
                break;
            case 7:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                loggedIn = loginUser(username, password);
                break;
            case 8:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    int choice;
    int codingLevel;
    char description[100];

    while (1) {
        printf("\n**마일리지 타임(아너코드!)**:\n");
        printf("9. Award Miles\n");
        printf("10. Print Transaction History\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 9:
                printf("Enter coding level: ");
                scanf("%d", &codingLevel);
                awardMiles(codingLevel);
                break;
            case 10:
                printTransactionHistory();
                break;
            case 11:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
return 0;
}
