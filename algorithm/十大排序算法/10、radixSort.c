/*
基数排序，时间复杂度：O(n)
*/

#include<stdio.h>
#include<malloc.h>
 
void radixSort(int *a, int count);
void countSort(int *bitNumber, int count, int *newA, int *c, int *a);
void showArray(int *a, int count);
 
void showArray(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);    
    }
    printf("\n");
}
 
void countSort(int *bitNumber, int count, int *newA, int *c, int *a){
    int i;
 
    // 从个位-->十位-->百位,每一次调用这个函数,辅助空间都必须初始化为0;
    for(i = 0; i < 10; i++){
        c[i] = 0;
    }
 
    for(i = 0; i < count; i++){
        c[bitNumber[i]]++;
    }
 
    for(i = 1; i < 10; i++){
        c[i] += c[i-1];
    }
 
    for(i = count-1; i >= 0; i--){
        newA[c[bitNumber[i]]-1] = a[i];  // a[i]与原先所取的位顺序一致
        c[bitNumber[i]]--;
    }
}
 
void radixSort(int *a, int count){
    int *bitNumber;
    int *newA;
    int c[10] = {0};
    int i;
 
    // 个位进行排序
    bitNumber = (int *)malloc(sizeof(int) * count);
    newA = (int *)malloc(sizeof(int) * count);
    for(i = 0; i < count; i++){
        bitNumber[i] = a[i]%10;
    }
    countSort(bitNumber, count, newA, c, a);  // bitNumber:代表要排的数字;newA:代表最终排行的新空间
                                             // c:代表辅助空间 a:代表原先数字
    for(i = 0; i < count; i++){
        a[i] = newA[i];
    }
 
    // 十位进行排序
    for(i = 0; i < count; i++){
        bitNumber[i] = a[i]/10%10;
    }
    countSort(bitNumber, count, newA, c, a);                      
    for(i = 0; i < count; i++){
        a[i] = newA[i];
    }
 
    // 百位排序
    for(i = 0; i < count; i++){
        bitNumber[i] = a[i]/100%10;
    }
    countSort(bitNumber, count, newA, c, a);  
                                      
    for(i = 0; i < count; i++){
        a[i] = newA[i];
    }
    // 千位排序
    for(i = 0; i < count; i++){
        bitNumber[i] = a[i]/1000%10;
    }
    countSort(bitNumber, count, newA, c, a);  
                                      
    for(i = 0; i < count; i++){
        a[i] = newA[i];
    }
 
}
 
void main(void){
    int a[] = {23, 1000, 90, 34, 2, 6, 3, 444, 555, 666, 777, 888, 999, 111, 222};
    int count = sizeof(a)/sizeof(int);
    radixSort(a, count);
    showArray(a, count);
}