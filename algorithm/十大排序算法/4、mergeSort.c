/*
归并排序，时间复杂度：O(nlogn)
*/

#include<stdio.h>
#include<malloc.h>
 
void mergeSort(int *a, int low, int high);
void merge(int *a, int low, int mid, int high);
 
void merge(int *a, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int n = 0;
    int *a2;
 
    a2 = (int *)malloc(sizeof(int) * (high-low+1));
    if(a2 == NULL){
        return;
    }
 
    // 以下都是<=,因为传过来的都是下标；
    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            a2[n++] = a[i];
            i++;
        }else if(a[i] == a[j]){
            a2[n++] = a[i];
            i++;
            j++;
        }else{
            a2[n++] = a[j];
            j++;
        }
    }
 
    while(i <= mid){
        a2[n++] = a[i];
        i++;
    }
    while(j <= high){
        a2[n++] = a[j];
        j++;
    }
 
    for(n = 0, i = low; i <= high; n++, i++){  // 将a2中的元素复制回a中;
        a[i] = a2[n];
    }
 
    free(a2);
}
 
void mergeSort(int *a, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}
 
void main(void){
    int a[] = {2, 4, 1, 7, 5, 6, 9, 10};
    int count = sizeof(a)/sizeof(int);
    int i;
 
    mergeSort(a, 0, count-1);
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
 
}