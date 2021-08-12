#include<stdio.h>
 
#define NOT_FOUND    -1;
 
int binSearch(int *a, int head, int tail, int key);
 
int binSearch(int *a, int head, int tail, int key){
    int middle;
 
    if(head <= tail){
        middle = (head + tail)/2;
 
        if(key == a[middle]){
            return middle;
        }
        if(key < a[middle]){
            return binSearch(a, head, middle-1, key);
        }
        if(key > a[middle]){
            return binSearch(a, middle+1, tail, key);
        }
    }
 
    return NOT_FOUND;
}
 
void main(void){
    int a[] = {2, 3, 4, 6, 8, 10};
    int count = sizeof(a)/sizeof(int);
    int index;
    int number;
 
    printf("请输入: ");
    scanf("%d", &number);
    index = binSearch(a, 0, count-1, number);
    printf("%d\n", index);
 
}