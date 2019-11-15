#include <stdio.h>
#pragma warning (disable : 4996)
#include <string.h>

int main(void){
    char name[20];
    
    printf("이름을 입력하시오 : ");
    fgets(name, sizeof(name),stdin);
    name[strlen(name)-1] = '\0';
    
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    return 0;
}
