#include<stdio.h>
 
typedef unsigned char boolean;
 
#define TRUE        1
#define FALSE        0
 
#define EIGHT    8
 
void showChess(int (*chess)[EIGHT]);  // 显示棋盘
boolean isSafe(int (*chess)[EIGHT], int row, int col); // 判断这个位置是否安全
void eightQueen(int (*chess)[EIGHT], int row);  // 八皇后的递归程序
 
void eightQueen(int (*chess)[EIGHT], int row){
    int colIndex;
     
    if(row >= EIGHT){
        showChess(chess);
    }else{
        for(colIndex = 0; colIndex < EIGHT; colIndex++){
            if(isSafe(chess, row, colIndex) == TRUE){
                chess[row][colIndex] = 1;
                eightQueen(chess, row+1);
                chess[row][colIndex] = 0;
            }
        }
    }
}
 
boolean isSafe(int (*chess)[EIGHT], int row, int col){
    int rowIndex;
    int colIndex;
 
    for(rowIndex = row-1; rowIndex >= 0; rowIndex--){
        if(chess[rowIndex][col] == 1){
            return FALSE;
        }
    }
    for(rowIndex = row-1, colIndex = col-1; rowIndex >= 0 && colIndex >= 0; rowIndex--, colIndex--){
        if(chess[rowIndex][colIndex] == 1){
            return FALSE;
        }
    }
    for(rowIndex = row-1, colIndex = col+1; rowIndex >= 0 && colIndex < EIGHT; rowIndex--, colIndex++){
        if(chess[rowIndex][colIndex] == 1){
            return FALSE;
        }
    }
 
    return TRUE;
}
 
void showChess(int (*chess)[EIGHT]){
    int i;
    int j;
    int static count;
 
    printf("解：%d\n", ++count);
    for(i = 0; i < EIGHT; i++){
        for(j = 0; j < EIGHT; j++){
            printf("%4d ", chess[i][j]);
        }
        printf("\n");
    }
}
 
void main(void){
    int chess[EIGHT][EIGHT] = {0};
 
    eightQueen(chess, 0);
}