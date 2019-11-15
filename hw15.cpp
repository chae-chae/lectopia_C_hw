#include <stdio.h>
#pragma warning (disable : 4996)

double inputWeight();
double inputHeight();
double calcBmi(double, double);
void output(double);

int main(void){
	double weight, height;
	double bmi;

	weight = inputWeight();
	height = inputHeight();
	bmi = calcBmi(weight, height);
	output(bmi);
	return 0;
}
double inputWeight(){
	double w;
	printf("몸무게를 입력하세요(kg) : ");
	scanf("%lf", &w);
	return w;
}
double inputHeight(){
	double h;
	printf("키를 입력하세요(m) : ");
	scanf("%lf", &h);
	return h;
}
double calcBmi(double w, double h){
	double res;
	res = w/(h*h);
	return res;
}
void output(double a){
	if (a<18.5){
		printf("당신의 BMI는 %.1lf으로 저체중입니다.\n", a);
	} else if (a<25.0){
		printf("당신의 BMI는 %.1lf으로 정상체중입니다.\n", a);
	} else if (a<30.0){
		printf("당신의 BMI는 %.1lf으로 과체중입니다.\n", a);
	} else if (a<40.0){
		printf("당신의 BMI는 %.1lf으로 비만입니다.\n", a);
	} else
		printf("당신의 BMI는 %.1lf으로 고도비만입니다.\n", a);
	return;
}
