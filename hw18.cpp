#include <stdio.h>
#pragma warning (disable : 4996)

int inputage(void);
int inputnum(void);
void printRes(int, int);

int main(void){
    int age, num;
    age = inputage();
    num = inputnum();
	printf("\n");
    printRes(age, num);
    return 0;
}
int inputage(void){
    int age;
    printf("입장객의 나이를 입력하시오 : ");
    scanf("%d", &age);
    return age;
}
int inputnum(void){
    int num;
    printf("입장객의 수를 입력하시오 : ");
    scanf("%d", &num);
    return num;
}
void printRes(int age, int num){
    int price = 0, sale = 0;
    if (age <= 7){
        price = num*500;
    } else if (age <= 13){
        price = num*700;
    } else if (age <= 19){
        price = num*1000;
    } else if (age <= 55){
        price = num*1500;
    } else {
        price = num*500;
    }
    if (num >= 5){
        sale = price*0.1;
    }
    printf("입장료 => %d원\n", price);
    printf("할인금액 => %d원\n", sale);
    printf("결제금액 => %d원\n", price-sale);
}
