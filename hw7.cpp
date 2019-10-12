#include <stdio.h>
#pragma warning (disable : 4996)

double inputKm(void);
double inputKmh(void);
void output(double, int, int, double);

int main(void){
	double km, kmh, hour;
	int ihour, min;
	double sec;

	km = inputKm();
	kmh = inputKmh();

	hour = km/kmh;
	ihour = (int)hour;
	min = (int)((hour-ihour)*60);
	sec =(((hour-ihour)*60)-min)*60;
	
	output(km, ihour, min, sec);
	return 0;
}
double inputKm(void){
	double km;
	printf("* 거리를 입력하시오(km단위) : ");
	scanf("%lf", &km);
	return km;
}
double inputKmh(void){
	double kmh;
	printf("* 시속을 입력하시오(km/h단위) : ");
	scanf("%lf", &kmh);
	return kmh;
}
void output(double km, int ihour, int min, double sec){
	printf("%.2lf km => %d시간 %d분 %.3lf 초 소요됨\n",km, ihour, min, sec);
	return;
}
