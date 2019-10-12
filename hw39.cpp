
#include <stdio.h>

int main(void){
    
    
    int i = 0, j;
    for (i = 0; i<100; i+=10){
    printf("%4d", i);
    }
    printf("\n");
    for (i = 1; i<10; i++) {
        for (j = 0; j<100; j+=10) {
            printf("%4d", i+j);
        }
        printf("\n");
    }
    
    return 0;
}
