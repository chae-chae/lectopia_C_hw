#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main(void){
    int a, b, res;
    
    while (1){
        printf("# 두개의 정수를 입력하세요 : ");
        res = scanf("%d %d", &a, &b);
        if ( res != 2 ){
            break;
        }
        if (a > b){
            printf("%d - %d = %d\n", a, b, a-b);
        } else {
            printf("%d - %d = %d\n", b, a, b-a);
        }
    }
    return 0;
}
