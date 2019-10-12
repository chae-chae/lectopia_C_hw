#include <stdio.h>
#pragma warning (disable : 4996)

int input(void);
int calc(int);
void output(int);

int main(void){
    int i = 0;
    int stnum, fee;
    while ( i < 5){
        stnum = input();
        fee = calc(stnum);
        output(fee);
        i++;
    }
    return 0;
}
int input(void){
    int stnum;
    printf("역수를 입력하시오 : ");
    scanf("%d", &stnum);
    return stnum;
}
int calc(int stnum){
    int fee, n;
    if (stnum <= 5){
        fee = 600;
    } else if (stnum <= 10){
        fee = 800;
    } else if (stnum % 2 == 0){
        n = (stnum-10) / 2;
        fee = 800 + 100*n;
    } else {
        n = ((stnum+1)-10) / 2;
        fee = 800 + 100*n;
    }
    return fee;
}
void output(int fee){
    printf("요금 : %d원\n", fee);
    return;
}
