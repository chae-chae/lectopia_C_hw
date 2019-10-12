#include <stdio.h>
#pragma warning (disable : 4996)

void myflush(void);
int menu(void);
void openFan(unsigned char *fan);
void offFan(unsigned char *fan);
void displayFan(unsigned char *fan);
void reverseFan(unsigned char *fan);

int main(void){
    unsigned char fan = 0;
    int m;
    
    m = menu();
    while (m != 4) {
        if(m == 1){
            openFan(&fan);
            displayFan(&fan);
            m = menu();
        } else if (m == 2){
            offFan(&fan);
            displayFan(&fan);
            m = menu();
        } else if (m == 3){
            reverseFan(&fan);
            displayFan(&fan);
            m = menu();
        }
    }
    return 0;
}
int menu(void){
    int m;
    while (1) {
        printf("\n1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
        scanf("%d", &m);
        if (m>=1 && m<=4 && getchar() == '\n'){
            break;
        }
        myflush();
        printf("1~4 중 입력해주세요.\n");
    }
    return m;
}

void myflush(void){
    while (getchar() != '\n') {
        ;
    }
    return;
}
void openFan(unsigned char *fan){
    unsigned char cmp = 0x1;
    int open;
    printf("--------------------------------------------------\n");
    printf("Fan 열기 작업 실행 화면\n");
    printf("--------------------------------------------------\n");
    while (1) {
        printf("* OPEN할 FAN 번호를 입력하시오(1-8) : ");
        scanf("%d", &open);
        if (open>=1 && open<=8 && getchar() == '\n'){
            break;
        }
        myflush();
        printf("1~8 중 입력해주세요.\n");
    }
    *fan = *fan | (cmp << (open-1));
}
void offFan(unsigned char *fan){
    char cmp = 0x01;
    int close;
    printf("--------------------------------------------------\n");
    printf("Fan 닫기 작업 실행 화면\n");
    printf("--------------------------------------------------\n");
    while (1) {
        printf("* CLOSE할 FAN 번호를 입력하시오(1-8) : ");
        scanf("%d", &close);
        if (close>=1 && close<=8 && getchar() == '\n'){
            break;
        }
        myflush();
        printf("1~8 중 입력해주세요.\n");
    }
    
    if(*fan >( *fan ^ (cmp << (close-1)))){
        *fan = *fan ^ (cmp << (close-1));
    } else {
        ;
    }
    
    //    if (close == 8){
//        *fan = *fan & 0x7f;
//    } else {
//
//        *fan = *fan & cmp >> ((close-8)+1);
//    }
    return;
}
void reverseFan(unsigned char *fan){
    printf("--------------------------------------------------\n");
    printf("Fan 전체 전환 작업 실행 화면\n");
    printf("--------------------------------------------------\n");
    printf("전체 FAN의 상태가 전환되었습니다. (ON, OFF 상태 뒤바뀜)\n");
    *fan = ~*fan;
    return;

}
void displayFan(unsigned char *fan){
    unsigned char cmp = 0x1;
    unsigned char res;
    int i;
    printf("--------------------------------------------------\n");
    printf("8번FAN  7번FAN  6번FAN  5번FAN  4번FAN  3번FAN  2번FAN  1번FAN\n");
    for (i = 8; i>0; i--){
        res = *fan & (cmp << (i-1));
        if (res == 0){
            printf("%-8s", "OFF");
        } else {
            printf("%-8s", "ON");
        }
    }
    printf("\n");
    return;
}
