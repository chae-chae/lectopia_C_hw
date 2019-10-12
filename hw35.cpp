#include <stdio.h>
#pragma warning (disable : 4996)

void myflush(void);
int inputInt(int *);

int main(void){
    int num, i;
    int sum = 0;
    
    for (i = 1; i<6; i++){
        printf("0 보다 큰 수를 입력하시오 (%d번째) : ", i);
        num = inputInt(&i);
        sum += num;
    }
    printf("입력된 값의 총 합 : %d\n", sum);
    return 0;
}
void myflush(void){
    while (getchar() != '\n') {
        ;
    }
    return;
}
int inputInt(int *ip){
    int n;
    while (1) {
        scanf("%d", &n);
        if ( n > 0 && (getchar() == '\n')){
            break;
        }
        myflush();
        printf("0 보다 큰 수를 입력하시오 (%d번째) : ", *ip);
    }
    return n;
}
