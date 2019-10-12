#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

void inputS(char *cp, char *sp);
int strcheck(char *sp, char ch);

int main(void) {

    char ch;
	char str[100] = {0};
    int res;
    
    inputS(&ch, str);
    
//    printf("%c", ch);
//    printf("%s", str);

    res = strcheck(str, ch);

    if (res == -1){
        printf("\"%s\"문자열 안에 '%c'문자는 존재하지 않습니다.\n", str, ch);
    } else {
        printf("\"%s\"문자열 안에 '%c'문자는 %d번 위치에 존재합니다.\n", str, ch, res);
    }
    
    return 0;
}

void inputS(char *cp, char *sp){
    
    printf("# 문자열을 입력하시오 : ");
	scanf("%s", sp);
    //fgets(sp, sizeof(sp), stdin);
    //sp[strlen(sp)] = '\0';
    printf("# 문자를 입력하시오 : ");
    scanf(" %c", cp);
    return;
}
int strcheck(char *sp, char ch){
    int i;
   // unsigned long len;

    //len = strlen(sp);
    
    for (i = 0; i<(int)strlen(sp); i++){
        if (sp[i] == ch){
            return i;
        }
    }


    return -1;
}
//void myflush(void){
//	while (getchar() != '\n'){
//		;
//	}
//}
