
#pragma warning (disable : 4996)
#include <stdio.h>


void output(int size, int arr[], const char *msg);
int inputArr(int arr[]);
void sort(int arr[], int size);

int main(void){

    int tc;
    int arr[100] = {0};
    int size;
    int i;
    
    printf("tc 입력 : ");
    scanf("%d", &tc);
    printf("tc = %d\n", tc);
    
    
    for (i = 0; i<tc; i++) {
        size = inputArr(arr);
        //printf("%d\n", size);
        output(size, arr, "# 소트 전 데이터 : ");
        sort(arr, size);
        output(size, arr, "# 소트 후 데이터 : ");
    }
    
    return 0;
}
int inputArr(int arr[]){
    int i, n = 0;
	printf("데이터를 입력하세요 (0입력하면 끝): ");
    for (i = 0; i<100; i++) {
        
        scanf("%d", &arr[i]);
        if (arr[i] == 0) {
            break;
        }
        n++;
    }
    return n;
}

void sort(int arr[], int size){
    int i, j;
    int tmp;

    for (i = 0; i<size; i++) {
        for (j = i+1; j<size; j++) {
            if (arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    return;
}

void output(int size, int arr[], const char *msg){
    int i;
    printf("%s", msg);
    for (i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}
