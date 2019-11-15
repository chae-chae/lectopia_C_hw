#include <stdio.h>

int main(void){
    
    int i, j, k;
    
    
    printf("<2중 for문을 이용한 출력>\n");
    for (i = 1; i<=9; i++){
        for (j = 2; j<=5; j++){
            printf("%d * %d = %d\t\t", j, i, j*i);
        }
        printf("\n");
    }
    printf("\n\n");
    for (i = 1; i<=9; i++){
        for (j = 6; j<=9; j++){
            printf("%d * %d = %d\t\t", j, i, j*i);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------\n");
    printf("<3중 for문을 이용한 출력>\n");
    
    
    for (i = 2; i<=9; i+=4){
        for (j = 1; j<=9; j++){
            for (k = i; k<=i+3; k++) {
                printf("%d * %d = %d\t\t", k, j, k*j);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    
    
    
    return 0;
}
