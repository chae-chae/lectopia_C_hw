#include <stdio.h>
#pragma warning (disable: 4996)

void myflush(void);
int inputInt(void);

int main(void){
    
    int n;
    int date = 0;
    int i, j, sum = 0;
    
    n = inputInt();
    
    for (i = 0 ; ;i++){

        for(j = 0; j<i; j++){

            sum += i;

            date++;

            if (date >= n){
                break;
            }
        }
        if (date >= n){
            break;
        }
    }
    
    printf("근무일 : %d 일  / 총 금화 수 : %d 개\n", n, sum);

    return 0;
}
int inputInt(void){
    int n;
    while(1){
        printf("* 기사의 근무일수를 입력하시오 : ");
        scanf("%d", &n);
        if (n>=0 && getchar() == '\n' ){
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
