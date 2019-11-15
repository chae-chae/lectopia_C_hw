#include <string.h>
#include <stdio.h>
#include <ctype.h>
#pragma warning (disable:4996)

int inputStr(char str[]);
int checkPal(char str[]);
void output(int res, char str[]);

int main(void){

    char str[100] = {0};
//    char end[10] = "end";
    int again, res;
    
    while (1) {
        again = inputStr(str);
        if (again == 0) {
            return 0;
        }
        res = checkPal(str);
//        printf("%d", res);
        output(res, str);
    }
    return 0;
}
int inputStr(char str[]){
    printf("# 단어 입력 : ");
    scanf("%s", str);
    if (strcmp(str, "end") == 0) {
        return 0;
    }
    return 1;
}
int checkPal(char str[]){
    char tmp[100] = {0};
    int len = (int)strlen(str);
    int i;
    for (i = 0; i<len; i++) {
        tmp[i] = tolower(str[i]);
//        printf("%c, %c\n", str[i], tmp[i]);
    }
    for (i = 0; i<len; i++) {
        if (tmp[i] != tmp[len-i-1]) {
            return 0;
        }
    }
    return 1;
}
void output(int res, char str[]){
    if (res == 1) {
        printf("\"%s\" : 회문입니다!\n", str);
    } else {
        printf("\"%s\" : 회문이 아닙니다!\n", str);
    }
    return;
}
