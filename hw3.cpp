#include <stdio.h>
#pragma warning (disable : 4996)

int main(void){
	int sec = 54321;
	int hr, m, rSec;

	hr = sec/(60*60);
	rSec = sec%(60*60);
	m = rSec/60;
	rSec %= 60;

	printf("%d초는 %d시간 %d분 %d초 입니다.\n", sec, hr, m, rSec);
	return 0;
}
