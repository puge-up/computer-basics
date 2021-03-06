#include<stdio.h>
 
    const int table[][10] = {   // table[3][6]代表：6的3次方，做一张表直接查询，效率比较高;
       // 0 1 2 3 4 5 6 7 8 9
/*0次方*/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
/*1次方*/ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
/*2次方*/ 0, 1, 2*2, 3*3, 4*4, 5*5, 6*6, 7*7, 8*8, 9*9,
/*3次方*/ 0, 1, 2*2*2, 3*3*3, 4*4*4, 5*5*5, 6*6*6, 7*7*7, 8*8*8, 9*9*9,
/*4次方*/ 0, 1, 2*2*2*2, 3*3*3*3, 4*4*4*4, 5*5*5*5, 6*6*6*6, 7*7*7*7, 8*8*8*8, 9*9*9*9,
/*5次方*/ 0, 1, 2*2*2*2*2, 3*3*3*3*3, 4*4*4*4*4, 5*5*5*5*5, 6*6*6*6*6, 7*7*7*7*7, 8*8*8*8*8, 9*9*9*9*9,
/*6次方*/ 0, 1, 2*2*2*2*2*2, 3*3*3*3*3*3, 4*4*4*4*4*4, 5*5*5*5*5*5, 6*6*6*6*6*6, 7*7*7*7*7*7, 8*8*8*8*8*8, 9*9*9*9*9*9,
/*7次方*/ 0, 1, 2*2*2*2*2*2*2, 3*3*3*3*3*3*3, 4*4*4*4*4*4*4, 5*5*5*5*5*5*5, 6*6*6*6*6*6*6, 7*7*7*7*7*7*7, 8*8*8*8*8*8*8, 9*9*9*9*9*9*9,
/*8次方*/ 0, 1, 2*2*2*2*2*2*2*2, 3*3*3*3*3*3*3*3, 4*4*4*4*4*4*4*4, 5*5*5*5*5*5*5*5, 6*6*6*6*6*6*6*6, 7*7*7*7*7*7*7*7, 8*8*8*8*8*8*8*8, 9*9*9*9*9*9*9*9,
/*9次方*/ 0, 1, 2*2*2*2*2*2*2*2*2, 3*3*3*3*3*3*3*3*3, 4*4*4*4*4*4*4*4*4, 5*5*5*5*5*5*5*5*5, 6*6*6*6*6*6*6*6*6, 7*7*7*7*7*7*7*7*7, 8*8*8*8*8*8*8*8*8, 9*9*9*9*9*9*9*9*9,
    };
 
void selfNumber(int num);
int selfLen(int num);
 
int selfLen(int num){
    if(num > 0 && num < 10){
        return 1;
    }else if(num > 10 && num < 100){
        return 2;
    }else if(num >100 && num < 1000){
        return 3;
    }else if(num > 1000 && num < 10000){
        return 4;
    }else if(num > 10000 && num < 100000){
        return 5;
    }else if(num > 100000 && num < 1000000){
        return 6;
    }else if(num > 1000000 && num < 10000000){
        return 7;
    }else if(num > 10000000 && num < 100000000){
        return 8;
    }else if(num > 100000000 && num < 1000000000){
        return 9;
    }
 
    return -1;
}
 
void selfNumber(int num){
    int n;
    int len = selfLen(num);
    int sum  =0;
 
    for(n = num; n; n/=10){
        sum += table[len][n%10]; // 此处就是求每一位的n次幂的和,利用的就是在表中直接查询的方法;
    }
 
    if(sum == num){
        printf("%d是自幂数\n", num);
    }
}
 
void main(void){
    int i;
    int count;
 
    printf("请输出多少位以内的自幂数：");
    scanf("%d", &count);
    for(i = 0; i < count; i++){
        selfNumber(i);
    }
}