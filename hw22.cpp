#pragma warning (disable :4996)
#include <stdio.h>

int input(void);

int main(void){
	int num;
	int i = 1;
	num = input();
	while (i<=num){
		if (i%5 == 0){
			printf("*\n");
		} else {
			printf("*");
		}
		i++;
	}
	printf("\n");
	return 0;
}
int input(void){
		int num;
		printf("# 정수값을 입력하세요 : ");
		scanf("%d", &num);
		return num;
}
