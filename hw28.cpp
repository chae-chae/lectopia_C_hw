#include <stdio.h>
#pragma warning (disable : 4996)


int main(void){
    char ch;
	int alpha = 0, num = 0, space = 0, etc = 0;
    
    
    printf("# 영문 문장을 입력 하시오 :\n");
    while ((ch = getchar()) != EOF) {
		if (('a'<= ch && 'z'>= ch) || ('A'<= ch && 'Z'>= ch)){
		alpha++;
		} else if ('0'<= ch && '9' >= ch){
			num++;
		} else if (ch == ' ' || ch == '\t' || ch == '\n'){
			space++;
		} else {
			etc++;
		}
	}
    printf("* 영문자 대소문자 개수 : %d개\n", alpha);
	printf("* 숫자문자 개수 : %d개\n", num);
	printf("* 여백문자(space, tab, enter) 개수 : %d개\n", space);
	printf("* 그외기타문자 개수 : %d개\n", etc);

    
    return 0;
}
