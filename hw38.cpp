#include <stdio.h>
#pragma warning (disable : 4996)

int main(void){

    int money;
    int i, j, k;
    int res = 0;
    int bcnt = 0, scnt = 0, ccnt = 0;

    while (1) {
        printf("현재 당신의 소유금액 입력 : ");
        scanf("%d", &money);
        if (getchar() != '\n'){
            return 0;
        }

        for (i = 1; i*500<money ; i++){
            bcnt++;
            for (j = 1; j*700<money; j++){
                scnt++;
                for(k = 1; k*400<money; k++){
                    ccnt++;
                    if ((500*i + 700*j + 400*k) == money){
                        printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", i, j, k);
                        res++;
                    }
                }
            }
        }
        if (res != 0){
            printf("어떻게 구입하시겠습니까?\n\n");
            res = 0;
        }
    }
    
    
    return 0;
}
