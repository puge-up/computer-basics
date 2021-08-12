/*
堆排序，时间复杂度：O(nlogn)
*/

#include<stdio.h>
 
void heapSort(int *a, int count);
void siftDown(int *a, int count, int start);
void swap(int *a, int *b);
int removeHeap(int *a, int n);
 
int removeHeap(int *a, int n){
    int key = a[0];
 
    a[0] = a[n];
    siftDown(a, n, 0);
 
    return key;
}
 
void swap(int *a, int *b){
    int tmp;
 
    tmp = *a;
    *a = *b;
    *b = tmp;
}
 
void siftDown(int *a, int count, int start){
    int i = start;
    int j = 2*i+1;
 
    while(j < count){  // 说明有左子树
        if(j < count-1 && a[j] > a[j+1]){ // 表示存在右孩子的情况下；
            j++;   // j：表示指向左右子树中最小的一个
        }
        if(a[i] <= a[j]){
            break;  // 不用调整，父节点的值是最小的；
        }else{
            swap(&a[i], &a[j]);
            // 交换
            i = j;  // 一直往树下交换，一直调整到叶子结点
            j = 2*i+1;
        }
    }
}
 
void heapSort(int *a, int count){
    int curPos = count/2-1; // 最后一个非叶子结点
    int i;
    int key;
 
    while(curPos >= 0){
        siftDown(a, count, curPos);
        curPos--;
    }
/*  输出构建好的堆结构
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
*/
 
    for(i = 0; i < count; i++){
        key = removeHeap(a, count-i-1);  // 传参：第二个参数是下标
        printf("%d ", key);
    }
    printf("\n");
}
 
void main(void){
    int a[] = {3, 5, 7, 1, 4, 2, 9, 10};
    int count = sizeof(a)/sizeof(int);
 
    heapSort(a, count);
}