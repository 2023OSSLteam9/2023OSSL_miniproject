#include "addfunc.h"

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int numUsers = 0;

struct Transaction {
    char description[100];
    int miles;
};

struct Transaction transactions[MAX_TRANSACTIONS];
int numTransactions = 0;
int totalMiles = 0;

//회원가입
int registerUser(const char *username, const char *password) { 
    if (numUsers >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return 0;
    }

    if (strlen(username) >= MAX_USERNAME_LENGTH || strlen(password) >= MAX_PASSWORD_LENGTH) {
        printf("Error: Username or password too long.\n");
        return 0;
    }

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Error: Username already exists.\n");
            return 0;
        }
    }

    struct User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);

    users[numUsers++] = newUser;
    printf("Registration successful.\n");
    return 1;
}

//로그인
int loginUser(const char *username, const char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                printf("Login successful.\n");
                return 1;
            } else {
                printf("Error: Invalid password.\n");
                return 0;
            }
        }
    }

    printf("Error: User not found.\n");
    return 0;
}

// 마일리지 지급
void addTransaction(const char* description, int miles) {
    if (numTransactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    struct Transaction newTransaction;
    strcpy(newTransaction.description, description);
    newTransaction.miles = miles;

    transactions[numTransactions++] = newTransaction;
    totalMiles += miles;

    printf("Transaction added successfully.\n");
}

//마일리지 내역 출력
void printTransactionHistory() {
    printf("Transaction History:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("Description: %s, Miles: %d\n", transactions[i].description, transactions[i].miles);
    }
    printf("Total Miles: %d\n", totalMiles);
    printf("\nPress enter to continue...");
    while(getchar() != '\n');        // 엔터를 누르기 전까지 메뉴로 돌아가지 않음
    getchar();                       // 입력 버퍼 제거
}

// 입력된 코딩 레벨에 따른 마일리지 지급
void awardMiles(int codingLevel) {
    int miles = 0;

    if (codingLevel >= 0 && codingLevel < 25) {
        miles = 10;
    } else if (codingLevel >= 25 && codingLevel < 50) {
        miles = 20;
    } else if (codingLevel >= 50 && codingLevel < 75) {
        miles = 30;
    } else if (codingLevel >= 75 && codingLevel <= 100) {
        miles = 50;
    } else {
        printf("Error: Invalid coding level.\n");
        return;
    }

    char description[100];
    sprintf(description, "Coding Level +%d", codingLevel);
    addTransaction(description, miles);
    printf("\nPress Enter to continue...");
    while(getchar() != '\n');        // 엔터를 누르기 전까지 메뉴로 돌아가지 않음
    getchar();                       // 입력 버퍼 제거
}
