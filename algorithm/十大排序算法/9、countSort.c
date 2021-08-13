/*
计数排序，时间复杂度：O(n)
*/

#include<stdio.h>
#include<malloc.h>
 
void countSort(int *a, int count);
void showArray(int *a, int count);
 
void showArray(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
void countSort(int *a, int count){
    int b[10] = {0};
    int *c;
    int i;
 
    c = (int *)malloc(sizeof(int) * count);
    for(i = 0; i < count; i++){
        b[a[i]]++;
    }
    for(i = 1; i < 10; i++){
        b[i] += b[i-1];
    }
 
    for(i = count-1; i >= 0; i--){
        c[b[a[i]]-1] = a[i];
        b[a[i]]--;
    }
 
    for(i = 0; i < count; i++){
        a[i] = c[i];
    }
 
    free(c);
 
}
void main(void){
    int a[] = {2, 4, 7, 2, 1, 0, 9};
    int count = sizeof(a)/sizeof(int);
 
    countSort(a, count);
    showArray(a, count);
}