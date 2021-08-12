#include<stdio.h>

#define NOT_FOUND	-1

int findMoreNum(int *a, int n);
int findMoreNum(int *a, int n){
    int result = a[0];
    int times = 1;
	int count = 0;
	int i;
    
    for(i = 1; i < n; i++){
        if(times == 0){
            result = a[i];
            times = 1;
        }else if(a[i] == result){
            times++;
        }else{
            times--;
        }
    }
    
    for(i = 0; i < n; i++){
        if(result == a[i])
            count++;
    }
    
    return count > n/2 ? result : NOT_FOUND;
}

void main(void){
	int a[] = {3, 5, 2, 8, 5, 2, 1, 2, 2, 2, 2,};
	int count = sizeof(a)/sizeof(int);
	int num;

	num = findMoreNum(a, count);
	if(num == NOT_FOUND){
		printf("Õâ¸öÊý×éÖÐÃ»ÓÐ³¬¹ýÒ»°ëÒÔÉÏµÄÊý×Ö\n");
	}else{
		printf("%d\n", num);
	}
}