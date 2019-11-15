#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)

void myflush(void);
int inputInt(void);
int primeNumber(int number);

int main(void){
    int i, j = 0;
    int n;
    int res = 0, cnt = 0;;
    
    n = inputInt();
    if (n == 1){
        printf("1은 소수가 아닙니다\n");
        return 0;
    }
    
    printf("1~%d까지의 소수 값은 다음과 같습니다.\n", n);
    
    for (i = 2; i<=n; i++){
        res = primeNumber(i);
        if (res == 1){
            printf("%-5d", i);
            j++;
            cnt++;
            if (j % 5 == 0){
                printf("\n");
            }
        }
    }
    printf("\n1~%d까지의 총 소수는 %d 개 입니다\n", n, cnt);

    return 0;
}
int inputInt(void){
    int n;
    while (1) {
        printf("*정수값 하나를 입력하세요 : ");
        scanf("%d", &n);
        if (n>0 && getchar() == '\n'){
            break;
        }
        myflush();
    }
    return n;
}
void myflush(void){
    while (getchar() != '\n') {
        ;
    }
    return;
}
int primeNumber(int number){
    int i;
    long double max = sqrt((long double)number);
    
    for (i = 2; i<=max; i++) {
        if (number % i == 0){
            return 0;
        } else {
            ;
        }
    }
    return 1;
}
