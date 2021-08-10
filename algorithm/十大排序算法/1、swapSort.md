算法题：交换排序算法

```cpp
#include<stdio.h>
 
void swapSort(int *a, int count);
void showArray(int *a, int count);
 
void showArray(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
 
    printf("\n");
}
 
void swapSort(int *a, int count){
    int i;
    int j;
    int tmp;
 
    for(i = 0; i < count; i++){
        for(j = 0; j < count-i-1; j++){
            if(a[j] > a[j+1]){ 
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
 
void main(void){
    int a[] = {3, 5, 7, 9, 1, 6, 10};
    int count = sizeof(a)/sizeof(int);
 
    swapSort(a, count);
    showArray(a, count);
}
```
