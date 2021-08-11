/*
希尔排序，时间复杂度：平均 O(nlogn)，最坏O(n^2)
*/

#include<stdio.h>
 
void insertSort(int *a, int count, int step);
void showArray(int *a, int count);
void shellSort(int *a, int count);
 
void shellSort(int *a, int count){
    int step;
 
    for(step = count/2; step > 0; step /= 2){
        insertSort(a, count, step);
    }
}
 
void showArray(int *a, int count){
    int i;
     
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
    printf("\n"); 
}
//ÒÔÏÂ¾ÍÊÇ²åÈëÅÅÐòÁË£¬Ë¼ÏëÍêÈ«Ò»Ñù£¬Ö»²»¹ý²½³¤Îªstep¶øÒÑ£¡£¡£¡
void insertSort(int *a, int count, int step){
    int i;
    int j;
    int n;
    int tmp;
 
    for(i = step; i < count; i+=step){
        tmp = a[i];
        for(j = 0; a[i]>a[j] && j<i; j+=step){
            ;
        }
        if(i != j){
            for(n = i; n > j; n-=step){
                a[n] = a[n-step];
            }
            a[j] = tmp;
        }
    }
}
 
void main(void){
    int a[] = {2, 7, 1, 11, 0, 9, 8, 10};
    int count = sizeof(a)/sizeof(int);
 
    printf("ÅÅÐòÇ°Êä³öÈçÏÂ: ");
    showArray(a, count);
    shellSort(a, count);
    printf("ÅÅÐòºóÊä³öÈçÏÂ: ");
    showArray(a, count);
 
}