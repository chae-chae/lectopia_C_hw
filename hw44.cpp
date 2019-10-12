#include <stdio.h>
#pragma warning (disable : 4996)

void inputScope(int *sp, int *ep);
void myflush(void);
int inputOddeven(int *sp, int *ep);
void output(int res, int *sp, int *ep);

int main(void){

    int start, end;
    int res;
    
    inputScope(&start, &end);
    res = inputOddeven(&start, &end);
    output(res, &start, &end);

    return 0;
}
void inputScope(int *sp, int *ep){
    while (1) {
        printf("# 시작 값을 입력하시오 : ");
        scanf("%d", sp);
        if ( *sp > 0 && getchar() == '\n'){
            break;
        }
        myflush();
    }
    while (1) {
        printf("# 끝 값을 입력하시오 : ");
        scanf("%d", ep);
        if( *ep > *sp && getchar() == '\n'){
            break;
        }
        myflush();
    }
    return;
}
void myflush(void){
    while (getchar() != '\n') {
        ;
    }
    return;
}
int inputOddeven(int *sp, int *ep){
    char check;
    while (1) {
        printf("* %3d ~ %3d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", *sp, *ep);
        scanf(" %c", &check);
        if ((check == 'e' || check == 'o') && getchar() == '\n'){
            break;
        }
        myflush();
    }
    if (check == 'e'){
        return 2;
    } else {
        return 1;
    }
}
void output(int res, int *sp, int *ep){
    int sum = 0;
    int i;
    
    if (res == 2){
        printf("* %3d ~ %3d 까지의 짝수(", *sp, *ep);
        for (i = *sp; i<=*ep; i++){
            if (i%2 == 0){
                printf("%3d ", i);
                sum += i;
            }
        }
        printf(")의 합은 %d 입니다.\n", sum);
    } else {
        printf("* %3d ~ %3d 까지의 홀수(", *sp, *ep);
        for (i = *sp; i<=*ep; i++){
            if (i%2 != 0){
                printf("%3d ", i);
                sum += i;
            }
        }
        printf(")의 합은 %d 입니다.\n", sum);
    }
	return;
}
