#include <stdio.h>
#pragma warning (disable : 4996)

int main(void){
    int num;
    unsigned int cmp = 0x80000000;
    int res;
    int i = 0;
    
    printf("* 10진수 정수를 입력하시오 : ");
    scanf("%d", &num);
    printf("%d(10) = ", num);
    
    
    for (i = 0; i<32; i++){
        res = num & cmp;
        if (res == 0){
            printf("0");
        } else {
            printf("1");
        }
        cmp = cmp >> 1;
    }
    printf("(2)\n");
    return 0;
}
