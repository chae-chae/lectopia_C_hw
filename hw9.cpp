#include <stdio.h>
#pragma warning (disable : 4996)

int input(void);

int main(void){
    int number;
    number = input();
    printf("입력된 값은 8 진수로 %#o 입니다.\n", number);
    printf("입력된 값은 16 진수로 %#x 입니다.\n", number);
    return 0;
}
int input(void){
    int a;
    printf("정수값을 입력하세요 : ");
    scanf("%d", &a);
    return a;
}
