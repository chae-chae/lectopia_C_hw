#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void myflush(void);
int random(int);
int input(void);
void output(int, int);

int main(void){
    int num, ran;
    int cnt = 1;
    int min = 0, max = 101;
    srand((unsigned int)time(NULL));
    ran = random(100)+1;
    num = input();

    while (ran != num){
        cnt++;

        if (num > ran && max > num){
            max = num;
        } else if (num < ran && min < num){
            min = num;
        }
        output(min, max);
        num = input();
    }
    printf("우와 맞았다 추카추카~ %d 번째 만에 맞추셨습니다.\n", cnt);
    return 0;
}
void myflush(void){
    char ch;
    while((ch = getchar()) != '\n'){
        ;
    }
    return;
}
int random (int n){
    int ran;
    ran = rand()%n;
    return ran;
}

int input(void){
    int num, res;
    while (1){
        printf("# 숫자를 입력하시오 : ");
        res = scanf("%d", &num);
        if (res == 1 && num <=100 && num >=1){
            if (getchar() == '\n'){
                break;
            }
        }
        myflush();
    }
    return num;
}

void output(int min, int max){
    printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
    return;
}
