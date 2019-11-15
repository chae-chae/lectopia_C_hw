#include <stdio.h>
#pragma warning (disable : 4996)

int inputN(void);
void inputArr(int arr[], int size);
int check(int arr[], int size);

int main(void){
    
    int arr[1000] = {0};
    int size;
    int res;
    
    while (1) {
        size = inputN();
        if (size == 0){
            return 0;
        }
        inputArr(arr, size);
        res = check(arr, size);
        printf("# 서로 다른 수의 개수 : %d\n\n", res);
    }
 
    return 0;
}
int inputN(void){
    int size;
    printf("* 입력할 숫자의 개수 : ");
    scanf("%d", &size);
    if (getchar() != '\n') {
        return 0;
    }
    return size;
}
void inputArr(int arr[], int size){
    int i;
    printf("* 숫자 입력 : ");
    for (i = 0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    return;
}
int check(int arr[], int size){
    int i, j;
    int same = 0;
    int res;

    for (i = 0; i<size-1; i++) {
        for (j = i+1; j<size; j++){
            if (arr[i] == arr[j]) {
                if (arr[j] == 0){
                    break;
                }
                same++;
                arr[j] = 0;
            }
        }
    }
//    printf("size = %d\n same = %d\n", size, same);
    res = size - same;
    return res;
}
