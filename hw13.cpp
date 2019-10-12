#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main(void){
    char firstName[20], lastName[20];
    unsigned int flen, llen;
    
    printf("#성을 입력하시오 : ");
    scanf("%s", lastName);
    printf("#이름을 입력하시오 : ");
    scanf("%s", firstName);
    
    llen = strlen(lastName);
    flen = strlen(firstName);
    
    printf("%s", lastName);
    printf("%*s", flen+1,firstName);
    printf("\n");
    printf("%*d", llen, llen);
    printf("%*d\n", flen+1, flen);
    
    return 0;
}
