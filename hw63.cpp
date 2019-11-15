#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

int inputNum(int arr[]);
int jollyjumper(int arr[], int size);

int main(void){
    
    int arr[100];
    int size, jolly;
    int i;
    
    size = inputNum(arr);
    
    printf("검사한 수열 : ");
    for (i =0; i<size; i++){
        printf("%d ", arr[i]);
    }

    jolly = jollyjumper(arr, size);
    
    if (jolly == 1) {
        printf("(Jolly jumper)\n");
    } else {
        printf("(Not jolly jumper)\n");
    }
    
    return 0;
}
int inputNum(int arr[]){
    int size;
    int i;
    printf("# 숫자를 입력하세요(첫번째는 수열내의 숫자의 개수/두번째부터 검사할 수열): ");
    scanf("%d", &size);
    for (i = 0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    return size;
}
int jollyjumper(int arr[], int size){
    int jolly; // 1 : 졸리점프  0 : 아님
    int tmp[100] = {0};
    int i, j, temp;
    
    if (size == 1) {//숫자 하나만 있는거면 무조건 졸리점퍼
        return 1;
    }
    for (i = 0; i<size; i++) {
        tmp[i] = abs(arr[i] - arr[i+1]);
    }
    for (i = 0; i<size-1; i++) { //sort
        for (j = i+1; j<size-1; j++) {
            if (tmp[i]>tmp[j]) {
                temp = tmp[j];
                tmp[j] = tmp[i];
                tmp[i] = temp;
            }
        }
    }
//    for (i = 0; i<size-1; i++)
//    {printf("\n%d ", tmp[i]);}
    for (i = size-2; i>0; i--) {
        if (tmp[i] - tmp[i-1] != 1){
            return 0;
        } else {
            ;
        }
    }
    jolly = 1;
    
    return jolly;
}
