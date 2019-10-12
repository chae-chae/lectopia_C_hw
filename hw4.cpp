#include <stdio.h>

int main(void){
    double year = 365.2422;
    int day;
    int ihr, min;
    double dhr, sec;
    
    day = (int)year;
    dhr = (year-day)*24;
	ihr = (int)dhr;
    min = (int)((dhr-ihr)*60);
	sec = (((dhr-ihr)*60)-min)*60;
    
    printf("%.4lf는 %d일 %d시간 %d분 %.2lf초입니다.\n", year, day, ihr, min, sec);
    return 0;
}
