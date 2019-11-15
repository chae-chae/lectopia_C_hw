#include <string.h>
#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)

int inputStr(char str[]);
int lengthStr(char str[]);
int calc(char str[], int size);
void output(char str[], int sum);

int main(void){
    
    char str[100];
    int again, len;
    int sum;
    
    while (1) {
        again = inputStr(str);
        if (again == 0) {
            return 0;
        }
        len = lengthStr(str);
        sum = calc(str, len);
        output(str, sum);
    }
    return 0;
}
int inputStr(char str[]){
    printf("# 문장을 입력하시오 : ");
    scanf("%s", str);
    if (strcmp(str, "end") == 0) {
        return 0;
    }
    return 1;
}
int calc(char str[], int len){
    int sum = 0, cnt = 0;
    int i;
    for (i = len-1; i>=0; i--) {
        if ( ((str[i] - '0') >= 0) && ((str[i] - '0') <= 9) ){
            sum += ((str[i] - '0') * (int)pow(10, (long double)cnt));
            cnt++;
        } else {
            cnt = 0;
            continue;
        }
    }
    return sum;
    }
int lengthStr(char str[]){
    int len = (int)strlen(str);
    return len;
}
void output(char str[], int sum){
    printf("\"%s\" 내의 총 숫자는 [%d]입니다.\n", str, sum);
    return;
}
