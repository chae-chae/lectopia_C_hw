#include <stdio.h>
#pragma warning (disable : 4996)

int inputYear(void);
int yearCheck(int);
void output(int, int);

int main(void){
    int year, check;
    year = inputYear();
    check = yearCheck(year);
    output(year, check);
    return 0;
}
int inputYear(void){
    int year;
    printf("년도를 입력하시오 : ");
    scanf("%d", &year);
    return year;
}
int yearCheck(int year){
    if (year%4 != 0){
        return 0;
    } else if (year%100 != 0){
        return 1;
    } else if (year%400 == 0){
        return 1;
    } else {
        return 0;
    }
}
void output(int year, int check){
    if (check == 1){
        printf("%d년은 윤년(Leap year)입니다.\n", year);
    } else {
        printf("%d년은 평년(Common year)입니다.\n", year);
    }
    return;
}
