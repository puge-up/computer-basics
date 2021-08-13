#include<stdio.h>
 
#define N    10
 
int LCS(int *a, int count1, int *b, int count2);
int LCS(int *a, int count1, int *b, int count2){
    int table[N][N] = {0};
    int i;
    int j;
 
    for(i = 0; i < count1; i++){
        for(j = 0; j < count2; j++){
            if(a[i] == b[j]){
                table[i+1][j+1] = table[i][j]+1;
            }else{
                table[i+1][j+1] = table[i+1][j] > table[i][j+1] ? table[i+1][j] : table[i][j+1];
            }
        }
    }
 
    return table[count1][count2];
}
 
void main(void){
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {2, 3, 5, 6, 7};
    int count1 = sizeof(a)/sizeof(int);
    int count2 = sizeof(b)/sizeof(int);
    int number;
 
    number = LCS(a, count1, b, count2);
    printf("%d\n", number);
}