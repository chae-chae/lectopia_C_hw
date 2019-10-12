#include <stdio.h>
#pragma warning (disable : 4996)

void myflush(void);

int main(void){
    
    long long f1 = 1, f2 = 1, f3;
    long long sum = 0;
    int n, i;
    
    printf("피보나치 수열의 항수를 입력하시오 : ");
    while (1) {
        scanf("%d", &n);
        if (1<= n && n<= 30 && getchar() == '\n'){
            break;
        }
        myflush();
        printf("1~30 사이의 수를 입력하세요 : ");
    }
    if( n <= 1){
        printf("%lld = %lld\n", f1, f1);
    } else if (n <= 2){
        printf("%lld + %lld = %lld\n", f1, f2, f1+f2);
    } else {
        printf("%lld + %lld + ", f1, f2);
        for (i = 1; i<n-1; i++) {
            f3 = f1 + f2;
            printf("%lld ", f3);
            if (i < n-2){
                printf("+ ");
            }
            sum += f3;
            f1 = f2;
            f2 = f3;
        }
    printf("= %lld\n", sum+2);
    }
    return 0;
}
void myflush(void){
    while (getchar() != '\n') {
        ;
    }
    return;
}
