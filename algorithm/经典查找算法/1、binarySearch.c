#include<stdio.h>

#define NOT_FOUND	-1

int binarySearch(int *a, int count, int key);

int binarySearch(int *a, int count, int key){
	int head = 0;
	int tail = count-1;
	int mid;

	while(head <= tail){
		mid = (head + tail) / 2;
		if(a[mid] > key){
			tail = mid-1;
		}else if(a[mid] < key){
			head = mid + 1;
		}else{
			return mid;	
		}
	}

	return NOT_FOUND;
}

void main(void){
	int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17,};
	int count = sizeof(a)/sizeof(int);
	int key;
	int index;

	scanf("%d", &key);
	index = binarySearch(a, count, key);
	if(index == NOT_FOUND){
		printf("要查找的数在数组中不存在\n");	
	}else{
		printf("%d %d\n", index, a[index]);
	}	
}