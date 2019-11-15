#include <stdio.h>
#pragma warning (disable:4996)

void swap(int num[], int size);

int main(void){

    int size, i;
    int num[] = {1, 2, 3, 4, 5};
    size = sizeof(num)/sizeof(num[0]);
    
    printf("처음 배열에 저장된 값 : ");
    for (i = 0; i<size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    
    swap(num, size);
    
    printf("바뀐 배열에 저장된 값 : ");
    for (i = 0; i<size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
void swap(int num[], int size){
    int a, b, i;
    for (i = 0; i<size/2; i++) {
        a = num[i];
        b = num[size-1-i];
        num[size-1-i] = a;
        num[i] = b;
    }
    return;
}
