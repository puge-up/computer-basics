#include<stdio.h>

typedef unsigned char boolean;

#define TRUE	1
#define FALSE	0

boolean findNum(int (*a)[4], int rowCount, int colCount, int key);

boolean findNum(int (*a)[4], int rowCount, int colCount, int key){
    int i;
    int j;
    
    for(i = rowCount-1, j = 0; i >= 0 && j < colCount;){
        if(key == a[i][j]){
            return TRUE;
        }
        if(key < a[i][j]){
            i--;
            continue;
        }
        if(key > a[i][j]){
            j++;
            continue;
        }
    }
    
    return FALSE;   	
}

void main(void){
	int a[4][4] = {
		1,  2,  3,  4,
        5,  6,  7,  8,
		9,  10, 11, 12,
		13, 14, 15, 16,
	};
	boolean flag;

	flag = findNum(a, 4, 4, 5);
	if(flag){
		printf("找到了\n");
	}else{
		printf("没找到\n");
	}
}