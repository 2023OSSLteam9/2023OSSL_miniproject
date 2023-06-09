#include "product.h"
#include "addfunc.h"

int main(){

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome!\n");

    int loggedIn = 0;
    while (!loggedIn) {
        int choice;
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                registerUser(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                loggedIn = loginUser(username, password);
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

        if (loggedIn) {
            int count = 0, index = 0, menu;
            content *cp[100];

            count = loadData(cp);
            index = count;

                int choice;
                int codingLevel;
                char description[100];

    while(1){
    menu = selectMenu();
    if(menu == 0){
        printf("Program has been quitted successfully."); 
        break;
    }
    else if(menu == 2){
        cp[index] = (content *)malloc(sizeof(content));
        count += addContent(cp[index++]);
        }
    else if(menu == 1|| menu == 3 || menu == 4){        //  2로 추가된 데이터가 없을 경우 1,3,4를 하면 되돌아가기
        if(count <= 0){
            printf("No Data exists.\n"); continue;
        }
    }
    if(menu == 1) showContent(cp, index);
    else if(menu == 3) modifyContent(cp, index);
    else if(menu == 4){ int num = cancelContent(cp, index);
                if (num == 0) {
                printf("=> cancelled successfully.\n");
                continue;
            }
        free(cp[num-1]);
        cp[num-1] = NULL;
        count--;
        printf("\ndeleted successfully.\n");
        }
    else if(menu == 5){
        saveData(cp, index);
    }
    else if (menu == 6) {
        printf("Enter coding level: ");
        scanf("%d", &codingLevel);
        awardMiles(codingLevel);
    }
    else if (menu == 7) printTransactionHistory();
        }
    }
}