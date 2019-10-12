#include <stdio.h>
#pragma warning (disable : 4996)

double inputF(void);
void output(double);

int main(void){
	double C, F;

	F = inputF();
	C = (double)5/9*(F-32);
	output(C);
	return 0;
}
double inputF(void){
	double F;
	printf("화씨 온도를 입력하세요 : ");
	scanf("%lf", &F);
	return F;
}
void output(double C){
	printf("섭씨 온도는 %.1lf 도입니다.\n", C);
	return;
}
