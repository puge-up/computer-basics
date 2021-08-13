#include<stdio.h>
 
//最大子数字和：贪心算法,时间复杂度为：O(n)
int maxSubArray(int *a, int n);
int maxSubArray(int *a, int n){
    int i;
    int ans = -10000000;
    int sum = 0;
 
    for(i = 0; i < n; i++){
        sum += a[i];
        if(sum > ans){
            ans = sum;  //保存先前的最大值
        }
        if(sum < 0){
            sum = 0; //将一部分和<0的直接删去
        }
    }
 
    return ans;
}

void main(void){
    int a[] = {-1, -2, 3, 6, -6, 3, 3, 2, -3};
    int count = sizeof(a)/sizeof(int);
    int maxNumber;
 
    maxNumber = maxSubArray(a, count);
    printf("%d\n", maxNumber);
}