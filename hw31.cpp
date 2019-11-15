#include <stdio.h>
#pragma warning (disable : 4996)

char menu(void);
int inputInt(const char * msg);
void myflush(void);
void deposit(int * dp);
void withdraw(int * wp);

int main(void){
    int balance = 0;
    char m;
    printf("* 현재 잔액은 %d원 입니다.\n\n", balance);
    m = menu();
    while (m != 'q') {
        if (m == 'i'){
            deposit(&balance);
            m = menu();
        } else if (m == 'o'){
            withdraw(&balance);
            m = menu();
        }
    }
    
    return 0;
}
char menu(void){
    char m;
    while (1) {
        printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
        m = getchar();
        if (m == 'i' || m == 'o' || m == 'q'){
            break;
        }
        myflush();
        printf("* 잘못 입력하셨습니다.\n\n");
    }
    return m;
}
void myflush(void){
    while ( getchar() != '\n' ){
        ;
    }
    return;
}
int inputInt(const char * msg){
    int n;
    while (1) {
        printf("%s", msg);
        scanf("%d", &n);
        if (getchar() == '\n'){
            break;
        }
        myflush();
    }
    return n;
}
void deposit(int * dp){
    int dep;
    dep = inputInt("# 입금액을 입력하세요 : ");
    while (1) {
        if (dep > 0){
            break;
        } else{
            dep = inputInt("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
        }
    }
    *dp += dep;
    printf("* 현재 잔액은 %d원 입니다.\n\n", *dp);
    
    return;
}
void withdraw(int * wp){
    int wit;
    wit = inputInt("# 출금액을 입력하세요 : ");
    if ( *wp < wit){
        printf("* 잔액이 부족합니다.\n");
        printf("* 현재 잔액은 %d원 입니다.\n\n", *wp);
        return;
    } else {
        while (1) {
            if (wit > 0){
                break;
            } else {
                wit = inputInt("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
            }
        }
        *wp -= wit;
        printf("* 현재 잔액은 %d원 입니다.\n\n", *wp);
        }
    return;
}
