#include <stdio.h>
#pragma warning (disable:4996)
void myflush(void);

int main(void){

    char ch;
    char i, j;
    
    
    while (1) {
        printf("* 영문자 대문자 입력('A'~'Z') : ");
        scanf("%c", &ch);
        if ('A' <= ch && ch <= 'Z'){
            for ( i = ch; i>='A'; i--){
                for (j = ch; j>=i; j--){
                    printf("%c", j);
                }
                printf("\n");
            }
            myflush();
        } else {
            break;
        }
    }




    return 0;
}
void myflush(void){
    while (getchar() != '\n') {
        ;
    }
    return;
}
