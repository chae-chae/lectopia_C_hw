#include <stdio.h>
#pragma warning (disable : 4996)

double input(void);
void output(double fee);

int main(void){
	double fee, kw;

	kw = input();
	fee = 660+(kw*88.5);
	fee += fee*0.09;
	output(fee);
	return 0;
}
double input(void){
	double kw;
	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%lf", &kw);
	return kw;
}
void output(double fee){
	printf("전기 사용요금은 %lf 원 입니다.\n", fee);
	return;
}
