#pragma warning (disable : 4996)
#include <stdio.h>

int input(void);
int gpcalc(int);
int taxcalc(int);
void output(int, int);

int main(void){
	int hour, glosspay, tax;

	hour = input();
	glosspay = gpcalc(hour);
	tax = taxcalc(glosspay);
	output(glosspay, tax);
	return 0;
}
int input(void){
	int hour;
	printf("*1주일간의 근무시간을 입력하시오 : ");
	scanf("%d", &hour);
	return hour;
}
int gpcalc(int hour){
	int glosspay;
	if (hour > 40){
		glosspay = (int)(40*3000 + (hour-40)*3000*1.5);
	} else {
		glosspay = hour*3000;
	}
	return glosspay;
}
int taxcalc(int glosspay){
	int tax;
	if (glosspay > 100000){
		tax = (int)((100000*0.15)+((glosspay-100000)*0.25));
	} else {
		tax = (int)(glosspay*0.15);
	}
	return tax;
}
void output(int glosspay, int tax){
	printf("# 총수입 : %7d원\n", glosspay);
	printf("# 세  금 : %7d원\n", tax);
	printf("# 실수입 : %7d원\n", glosspay-tax);
	return;
}
