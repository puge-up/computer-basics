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
 
    while(j < count){  //ËµÃ÷ÓÐ×ó×ÓÊ÷
        if(j < count-1 && a[j] > a[j+1]){ //±íÊ¾´æÔÚÓÒº¢×ÓµÄÇé¿öÏÂ£»
            j++;   //j£º±íÊ¾Ö¸Ïò×óÓÒ×ÓÊ÷ÖÐ×îÐ¡µÄÒ»¸ö
        }
        if(a[i] <= a[j]){
            break;  //²»ÓÃµ÷Õû£¬¸¸½ÚµãµÄÖµÊÇ×îÐ¡µÄ£»
        }else{
            swap(&a[i], &a[j]);
            //½»»»
            i = j; //Ò»Ö±ÍùÊ÷ÏÂ½»»»£¬Ò»Ö±µ÷Õûµ½Ò¶×Ó½áµã
            j = 2*i+1;
        }
    }
}
 
void heapSort(int *a, int count){
    int curPos = count/2-1; //×îºóÒ»¸ö·ÇÒ¶×Ó½áµã
    int i;
    int key;
 
    while(curPos >= 0){
        siftDown(a, count, curPos);
        curPos--;
    }
/*  Êä³ö¹¹½¨ºÃµÄ¶Ñ½á¹¹
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
*/
 
    for(i = 0; i < count; i++){
        key = removeHeap(a, count-i-1);  //´«²Î£ºµÚ¶þ¸ö²ÎÊýÊÇÏÂ±ê
        printf("%d ", key);
    }
    printf("\n");
}
 
void main(void){
    int a[] = {3, 5, 7, 1, 4, 2, 9, 10};
    int count = sizeof(a)/sizeof(int);
 
    heapSort(a, count);
}