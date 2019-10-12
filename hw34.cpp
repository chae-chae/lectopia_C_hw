#include <stdio.h>
#pragma warning (disable : 4996)

int inputInt(const char *msg);
void myflush(void);
double calcfee(int code, int water);
void output(int code, int water, double fee);

int main(void){
    int code, water;
    double fee;
    
    code = inputInt("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
    while (code != 1 && code != 2 && code != 3) {
        code = inputInt("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
    }
    water = inputInt("* 사용량을 입력하시오(ton단위) : ");
    
    switch (code) {
        case 1:
            fee = calcfee(code, water);
            output(code, water, fee);
            break;
        case 2:
            fee = calcfee(code, water);
            output(code, water, fee);
            break;
        case 3:
            fee = calcfee(code, water);
            output(code, water, fee);
            break;
        default:
            ;
            break;
    }
}
int inputInt(const char *msg){
    int n;
    while (1) {
        printf("%s", msg);
        scanf("%d", &n);
        if (n>= 0 && (getchar() == '\n')){
            break;
        }
        myflush();
    }
    return n;
}
void myflush(void){
    while (getchar() != '\n') {
        ;
    }
    return;
}
double calcfee(int code, int water){
    double fee;
    if (code == 1){
        fee = water*50;
        fee = fee + fee*0.05;
    } else if (code == 2){
        fee = water*45;
        fee = fee + fee*0.05;
    } else {
        fee = water*30;
        fee = fee + fee*0.05;
    }
    return fee;
}
void output(int code, int water, double fee){
    printf("\n# 사용자코드 : %d", code);
    if (code == 1){
        printf("(가정용)\n");
    } else if (code == 2){
        printf("(상업용)\n");
    } else {
        printf("(공업용)\n");
    }
    printf("# 사용량 : %d ton\n", water);
    printf("# 총수도요금 : %.0lf원\n", fee);
    return;
}
