#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int input(void);
int calc(int cdepth);
void output(int, int);

int main(void){
    int cdepth, day;
    
    cdepth = input();
    day = calc(cdepth);
    output(cdepth, day);
    
    return 0;
}

int input(void){
    int cdepth;
    printf("* 우물의 깊이를 입력하시오(cm단위) : ");
    scanf("%d", &cdepth);
    return cdepth;
}
int calc(int cdepth){
    int day = 0;
    while(cdepth >= 0){
        if (cdepth == 0){ break; }
        day++;
        cdepth -= 50;
        if (cdepth <= 0){ break; }
        cdepth += 20;
    }
    return day;
}
void output(int cdepth, int day){
    double mdepth;
    mdepth = (double)cdepth/100;
    printf("%.2lf 미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", mdepth, day);
    return;
}
