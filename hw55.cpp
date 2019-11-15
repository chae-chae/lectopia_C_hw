#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void arrRandom(int num[][4]);
void outputArr(int num[][4]);

int main(void){
    
    int num[3][4];
    srand((unsigned int)time(NULL));
    
    arrRandom(num);
    outputArr(num);
    
    return 0;
}
void arrRandom(int num[][4]){
    int i, j;
    for (i = 0; i<3; i++){
        for (j = 0; j<4; j++) {
            num[i][j] = rand()%9 + 1;
        }
    }
    return;
}
void outputArr(int num[][4]){
    int i, j;
    int rowsum = 0, colsum = 0;
    
    for (i = 0; i<3 ; i++){
        printf("%d%-7s:", i, "행", ":");
        
        for (j = 0; j<4; j++) {
            printf("%5d", num[i][j]);
            rowsum += num[i][j];
        }
        printf("%5d행의 합 : %d\n", i, rowsum);
        rowsum = 0;
    }
    printf("열의 합 :");
    for (i = 0; i<=3 ; i++){
        for (j = 0; j<=2; j++) {
            colsum += num[j][i];
        }
        printf("%5d", colsum);
        colsum = 0;
    }
    
    return;
}

