#pragma warning (disable : 4996)
#include <stdio.h>
#define ASIZE 5

void myflush(void);
void inputArr(double *np, int cnt);
double maxD(double *xp, int cnt);
double minD(double *xp, int cnt);
void output(double max, double min);

int main(void){
    int size;
    double max, min;
    double num[ASIZE];      //더블형 num 배열 선언, ASIZE 5 define
    size = sizeof(num) / sizeof(num[0]);

    inputArr(num, size);
    max = maxD(num, size);
    min = minD(num, size);

    output(max, min);

    return 0;
}
void inputArr(double *np, int cnt){ //더블형 배열의 주소와 얼만큼 받을지
    int i;
    for ( i = 0; i<cnt; i++){
        while (1) {
            printf("%d번 방 값 : ", i);
            scanf("%lf", &np[i]);   //np는 num의 시작주소를 갖고잇당 즉 np=num인거
            if (getchar() == '\n'){
                break;
            }
            myflush();
        }
    }
    return;
}
void myflush(void){
    while ( getchar() != '\n'){
        ;
    }
    return;
}
double maxD(double *xp, int cnt){
    int i;
    double max = xp[0];
    for (i = 1; i<cnt; i++){
        if (max < xp[i]){
            max = xp[i];
        }
    }
    return max;
}
double minD(double *xp, int cnt){
    int i;
    double min = xp[0];
    for (i = 1; i<cnt; i++){
        if (min > xp[i]) {
            min = xp[i];
        }
    }
    return min;
}
void output(double max, double min){
    printf("\n가장 큰 값 : %.2lf\n", max);
    printf("가장 작은 값 : %.2lf\n", min);
    return;
}
