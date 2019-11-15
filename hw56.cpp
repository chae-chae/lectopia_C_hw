#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

void aryRandom(int (*ap)[5]);
void arySum(int (*ap)[5], int *s1p, int *s2p, int *s3p);
void output(int (*ap)[5], int *s1p, int *s2p, int *s3p);

int main(void){

    int ary[5][5];
    int sum1 = 0, sum2 = 0, sum3 = 0;
    
    srand((unsigned int)time(NULL));
    
    aryRandom(ary);
    arySum(ary, &sum1, &sum2, &sum3);
    output(ary, &sum1, &sum2, &sum3);

    
    return 0;
}
void aryRandom(int (*ap)[5]){
    int i, j;
    for (i = 0; i<5; i++) {
        for (j = 0; j<5; j++) {
            ap[i][j] = rand()%20+1;
        }
    }
    return;
}
void arySum(int (*ap)[5], int *s1p, int *s2p, int *s3p){
    int i, j;
    
    for (i = 0; i<5; i++) {
        *s1p += ap[i][i];
    }
    for (i = 0; i<=3; i++) {
        for (j = 1+i; j<=4; j++) {
            *s2p += ap[i][j];
        }
    }
    for (i = 0; i<=3; i++) {
        for (j = 1+i; j<=4; j++) {
            *s3p += ap[j][i];
        }
    }
    
    return;
}
void output(int (*ap)[5], int *s1p, int *s2p, int *s3p){
    int i, j;
    for (i = 0; i<5; i++){
        printf("%d번 행 :", i);
        for (j = 0; j<5; j++) {
            printf("%-3d", ap[i][j]);
        }
        printf("\n");
    }
    printf("sum1 = %d\n", *s1p);
    printf("sum2 = %d\n", *s2p);
    printf("sum3 = %d\n", *s3p);

    return;
}
