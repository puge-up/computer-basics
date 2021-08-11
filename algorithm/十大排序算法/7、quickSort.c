/*
快速排序，时间复杂度：平均 O(nlogn)，最坏O(n^2)	
*/

#include<stdio.h>
 
int oneQuickSort(int *a, int i, int j);
void quickSort(int *a, int i, int j);
void showArray(int *a, int count);
 
void showArray(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void quickSort(int *a, int i, int j){
    int index;
 
    if(i < j){
        index = oneQuickSort(a, i, j);
        quickSort(a, i, index-1);
        quickSort(a, index+1, j);
    }
}
 
int oneQuickSort(int *a, int i, int j){
    int tmp;
 
    tmp = a[i];
    while(i < j){
        while(i < j && a[j] > tmp){
            j--;
        }
        if(i < j){
            a[i++] = a[j];
        }
        while(i < j && a[i] < tmp){
            i++;
        }
        if(i < j){
            a[j--] = a[i];
        }
    }
    a[i] = tmp;
 
    return i;
}
 
void main(void){
    int a[] = {3, 7, 1, 0, 9, -9,};
    int count = sizeof(a)/sizeof(int);
 
    quickSort(a, 0, count-1);
    showArray(a, count);
}