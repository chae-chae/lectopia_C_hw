#include <stdio.h>
#pragma warning (disable : 4996)

int input();
void myflush();

int main(void){
    int egg;
    int cnt = 0;
    
    while (cnt<10) {
        egg = input();
        if (egg < 150){
            printf("*메추리알 가지고 장난하지마세요~\n");
            continue;
        } else if (egg > 500){
            printf("*타조알 가지고 장난하지마세요~\n");
            continue;
        } else {
            cnt++;
            printf("*현재 달걀의 수 : %d\n", cnt);
        }
    }
    
    printf("***달걀 포장이 끝났습니다.\n");
    
    return 0;
}

int input(void){
    int egg;
    while (1) {
        printf("#계란의 무게를 입력하세요(단위 g) : ");
        scanf("%d", &egg);
        if (getchar() == '\n'){
            break;
        }
        myflush();
    }
    return egg;
}

void myflush(void){
    char ch;
    while((ch = getchar()) != '\n'){
        ;
    }
    return;
}
