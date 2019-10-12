#include <stdio.h>
#pragma warning (disable : 4996)

int transNumber(int);
int inputUint(const char *);
void output(int);
void myflush(void);

int main(void){
    int start, end, gozip;
    int i = 0;
    int res;
    int N = 0, cnt =0;
    
    
    start = inputUint("시작 값(P1) : ");
    while (start < 100) {
        start = inputUint("시작 값(P1) : ");
    }
    end = inputUint("끝 값(P2) : ");
    while (end > 10000) {
        end = inputUint("끝 값(P2) : ");
    }
    gozip = inputUint("고집수(N) : ");
    while (gozip < 1 || gozip > 10) {
        gozip = inputUint("고집수(N) : ");
    }
    printf("고집수가 %d인 숫자 출력\n", gozip);
    
    for (i = start; i<=end; i++){
        N = 0;
        res = transNumber(i);
        N++;
        while (res > 9) {
            res = transNumber(res);
            N++;
        }
        if (gozip == N){
            printf("%d\n", i);
            cnt++;
        }
    }
    output(cnt);
    
    return 0;
}
int inputUint(const char *msg){
    int n;
    while (1){
        printf("%s", msg);
        scanf("%d", &n);
        if (n >= 0){
            if (getchar() == '\n'){
                break;
            }
        }
        myflush();
    }
    return n;
}
int transNumber(int num){
    int res = 1;
    if (num>=10 && num<=99){
        res *= num%10;
        num /= 10;
        res *= num;
        return res;
    } else if (num>=100 && num<=999){
        res *= num%10;
        num /= 10;
        res *= num%10;
        num /= 10;
        res *= num;
        return res;
    } else if (num>=1000 && num<=9999){
        res *= num%10;
        num /= 10;
        res *= num%10;
        num /= 10;
        res *= num%10;
        num /= 10;
        res *= num;
        return res;
    } else {
        res = 0;
        return res;
    }
}
void myflush(void){
    while ( getchar() != '\n' ){
        ;
    }
    return;
}
void output(int cnt){
    printf("총 개수 : %d개\n", cnt);
    return;
}
