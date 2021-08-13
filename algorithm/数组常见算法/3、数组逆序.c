#include<stdio.h>
 
void arrayRev(int *a, int count);
void printT(int *a, int count);
 
void printT(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }   
}
void arrayRev(int *a, int count){
    int low = 0;
    int high = count-1;
    int tmp;
 
    while(low < high){
        tmp = a[low];
        a[low] = a[high];
        a[high] = tmp;
        low++;
        high--;
    }   
}
int main(void){
    int a[] = {1, 4, 2, 6, 8, 9, 11, 43, 12, 55,};
    int len;
 
    len = sizeof(a)/sizeof(a[0]);
 
    printf("排序前:\n");
    printT(a, len);
    arrayRev(a, len);
    printf("\n排序后:\n");
    printT(a, len);
    printf("\n");
 
    return 0;
}