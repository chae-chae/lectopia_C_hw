#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random (int n);
int input(void);
int output(int, int);
void myflush(void);

int main(void){
    int usr, com;
    int win = 0, draw = 0, res = 0;
    
    srand((unsigned int)time(NULL));
    usr = input();
    com = random(3)+1;
    res = output(usr, com);
    while (res != 2){
        if (res == 0){
            win++;
            usr = input();
            com = random(3)+1;
        } else {
            draw++;
            usr = input();
            com = random(3)+1;
        }
        res = output(usr, com);
    }
    printf("게임결과 : %d 승 %d 무\n", win, draw);
    return 0;
}
int random (int n){
    int ran;
    ran = rand()%n;
    return ran;
}
int input(void){
    int usr, res;
    while (1){
        printf("#바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
        res = scanf("%d", &usr);
            if (res == 1 && usr <= 3 && usr >=1){
                if (getchar() == '\n'){
                    break;
            }
        }
        myflush();
    }
    return usr;
}
void myflush(void){
    char ch;
    while((ch = getchar()) != '\n'){
        ;
    }
    return;
}
int output(int usr, int com){
    if (usr == 1){printf("당신은 바위 선택, ");
    }   else if (usr == 2){printf("당신은 가위 선택, ");
    }   else {printf("당신은 보 선택, ");}
    if (com == 1){printf("컴퓨터는 바위 선택 : ");
    }   else if (com == 2){printf("컴퓨터는 가위 선택 : ");
    }   else {printf("컴퓨터는 보 선택 : ");
    }
    if ((usr == 1 && com == 2) || (usr == 2 && com == 3) || (usr == 3 && com ==1)){
        printf("이겼습니다.\n");
        return 0; 
    } else if ((usr == 1 && com == 1) || (usr == 2 && com == 2) || (usr == 3 && com ==3)){
        printf("비겼습니다.\n");
        return 1; 
    } else {
        printf("당신이 졌습니다.\n");
        return 2;
    }
}
