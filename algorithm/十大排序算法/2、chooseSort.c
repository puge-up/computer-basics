/*
选择排序，时间复杂度：O(n^2)
*/

#include<stdio.h>
 
void sort(int *a, int count);
void showArray(int *a, int count);
 
void showArray(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);    
    }
    printf("\n");
}
 
void sort(int *a, int count){
    int i;
    int j;
    int tmp;
 
    for(i = 0; i < count; i++){
        for(j = i+1; j < count; j++){
            if(a[i] > a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
void main(void){
    int a[] = {3 ,5 ,6, 1, 7, 2, 9, 8};
    int count = sizeof(a)/sizeof(int);
 
    sort(a, count);
    showArray(a, count);
}
