#include <stdio.h>
#pragma warning (disable : 4996)

int main(void){
    int n;
    int i, j;

    while (1) {
        printf("출력 라인수를 입력하시오 : ");
        scanf("%d", &n);
        if ( getchar() != '\n'){
            return 0;
        }
        for (i = 1; i<=n; i++){
            for(j = 0; j<i; j++){
                printf("%-c", '*');
            }
            for(j = 0; j<2; j++)
            printf("%*c", n-i+1, ' ');
            for(j = 0; j<i; j++){
                printf("%c", '*');
            }
            printf("\n");

        }
    }

    return 0;
}
