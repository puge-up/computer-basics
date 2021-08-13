#include<stdio.h>
 
int secondMax(int *a, int len);
void printT(int *a, int count);
 
void printT(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int secondMax(int *a, int len){
    int max = a[0] > a[1] ? a[0] : a[1];
    int second = a[0] > a[1] ? a[1] : a[0];
    int i;
 
    for(i = 2; i < len; i++){
        if(a[i] > max){
            second = max;
            max = a[i];
        }else if(a[i] > second){
            second = a[i];
        }else{
            ;   
        }   
    }
    return second;
}
 
int main(void){
    int a[] = {44, 4, 66, 6, 8, 33, 22, 2 ,55 ,1};
    int len = sizeof(a)/sizeof(a[0]);
    int num;
 
    num = secondMax(a, len);
    printT(a, len);
    printf("%d\n", num);
 
    return 0;
}