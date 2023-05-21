#include "addfunc.h"
#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int numUsers = 0;

//회원가입 함수 구현
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

// 로그인 함수 구현
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


