/*
插入排序，时间复杂度：O(n^2)
*/

#include<stdio.h>
 
void insertSort(int *a, int count);
void showArray(int *a, int count);
 
void showArray(int *a, int count){
    int i;
     
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n"); 
}
 
void insertSort(int *a, int count){
    int i;
    int j;
    int n;
    int tmp;
 
    for(i = 1; i < count; i++){
        tmp = a[i];
        for(j = 0; a[i]>a[j] && j<i; j++){
            ;
        }
        if(i != j){
            for(n = i; n > j; n--){
                a[n] = a[n-1];
            }
            a[j] = tmp;
        }
    }
}
 
void main(void){
    int a[] = {2, 5, 7, 1, 11, 0, 6, 9};
    int count = sizeof(a)/sizeof(int);
 
    printf("排序前输出如下: ");
    showArray(a, count);
    insertSort(a, count);
    printf("排序后输出如下: ");
    showArray(a, count); 
}