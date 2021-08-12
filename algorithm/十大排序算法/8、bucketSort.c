/*
桶排序，时间复杂度：O(n)
*/

#include<stdio.h>
 
void bucketSort(int *a, int count);
void showArray(int *a, int count);
 
void showArray(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
void bucketSort(int *a, int count){
    int b[10] = {0};  // 知道要排序值的最大范围
    int i;
    int n = 0;
 
    for(i = 0; i < count; i++){
        b[a[i]]++;
    }
 
    for(i = 0; i < 10; i++){
        if(b[i]){
            a[n++] = i;
        }
    }
}
 
void main(void){
    int a[] = {3, 5, 1, 8, 9, 6};
    int count = sizeof(a)/sizeof(int);
 
    bucketSort(a, count);
    showArray(a, count);
}