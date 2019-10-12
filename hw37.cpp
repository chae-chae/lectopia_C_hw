#include <stdio.h>
#pragma warning (disable : 4996)

int main(void){

    int i;
    
    for (i = 1; i<=100; i++){
        if ((i % 3 == 0) && (i % 5 != 0)){
            printf("%3c", '*');
        } else if ((i % 5 == 0) && (i % 3 != 0)){
            printf("%3c", '#');
        } else if ((i % 3 == 0) && (i % 5 == 0)){
            printf("%3d", i);
        } else {
            printf("%3d", i);
        }
        if (i % 10 == 0){
            printf("\n");
        }
    }
    return 0;
}
