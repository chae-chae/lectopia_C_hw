#pragma warning (disable :4996)
#include <stdio.h>

int main(void){
	double height;
	double hsum = 0;
	int i = 1;
	while (i<=5){
		printf("- %d번 학생의 키는? ", i);
		scanf("%lf", &height);
		hsum += height;
		i++;
	}
	printf("다섯 명의 평균 키는 %.1lf cm 입니다.\n", hsum/5.0);
	return 0;
}
