#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

void inputStr(char (*sp)[20]);
void sortStr(char str[][20]);
void outputStr(char str[][20]);

int main(void){
    
    char str[5][20];

    inputStr(str);
    sortStr(str);
    outputStr(str);
    
    return 0;
}
void inputStr(char (*sp)[20]){
    int i;
    for (i = 0; i<5; i++){
        printf("# %d번 문자열을 입력하시오 : ", i+1);
        scanf("%s", sp[i]);
    }
    return;
}
void sortStr(char str[][20]){
    int i, j, res;
    char tmp[20];
    for (i = 0; i<5; i++)
        for (j = i+1; j<5; j++){
            res = strcmp(str[i], str[j]);
            if (res > 0){//뒤에거가 오름차쪽이면
                strcpy(tmp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], tmp);
            }
        }
    return;
}
void outputStr(char str[][20]){
    int i;
    for (i = 0; i<5; i++){
        printf("str[%d] = %s\t %c\t %c\n", i, str[i], str[i][0], str[i][(int)(strlen(str[i])-1)]);
    }
    return;
}
