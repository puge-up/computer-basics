#include<stdio.h>
#include<time.h>
#include<stdlib.h>
 
void showArray(int *a, int count);
void random_1(int *a, int count);
void random_1(int *a, int count){
    int i;
    int tmp;
    int index;
 
    srand(time(NULL));
    for(i = count; i > 0; i--){
        index = rand()%i;
        tmp = a[index];
        a[index] = a[i-1];
        a[i-1] = tmp;
    }
 
}
void showArray(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
 
int main(void){
    int a[] = {4, 6, 8, 2, 0, 7, 1,};
    int count = sizeof(a)/sizeof(int);
 
    showArray(a, count);
    random_1(a, count);
    showArray(a, count);
 
    return 0;
}