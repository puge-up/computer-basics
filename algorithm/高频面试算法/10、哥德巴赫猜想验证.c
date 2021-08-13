#include<stdio.h>
#include<math.h>
#include<malloc.h>
 
typedef unsigned char boolean;
 
#define    TRUE    1
#define    FALSE    0
 
// 位运算计算的效率更快
#define        SET_BIT(byte, i)    (byte |= 1 << (7 ^ (i)))  // 设置这个字节的指定位为1
#define        CLR_BIT(byte, i)    (byte &= ~(1 << (7 ^ (i)))) // 设置这个字节的指定位为0
#define        GET_BIT(byte, i)    !!((byte) & (1 << (7^(i))))  // 得到这个字节的指定位
 
// num >> 3  数组下标
// num & 7 <===> num % 8  
void findPrime(int number, char **p);
boolean isPrime(int num, char *p);
boolean Gguess(int userNumber, char *p);
 
boolean Gguess(int userNumber, char *p){
    int num;
    int i;
    int flag = TRUE;
 
    for(num = 6; TRUE == flag && num < userNumber; num += 2){ // 从6开始---userNumber的所有数字进行哥德巴赫猜想
        flag = FALSE;
        for(i = 3; i < num && FALSE == flag; i += 2){
            if(isPrime(i, p) && isPrime(num-i, p)){
                flag = TRUE;
                printf("%d = %d + %d\n", num, i, num-i);
            }
        }
    }
 
    return flag;
}
 
boolean isPrime(int num, char *p){
    return GET_BIT(p[num >> 3], num & 7) == 0;  // 0：表示为质数;
}
 
void findPrime(int number, char **p){
    int len = (int)(sqrt(number));
    int i;
    int j;
    char *pool;
 
    pool = (char *)calloc(sizeof(char), (number+7)>>3);
    for(i = 2; i < len; i++){  // 从2判断到根号number的长度即可
        if(GET_BIT(pool[i >> 3], i & 7) == 0){  
            for(j = i*i; j < number; j += i){  // 前面的都重复的判断过了
                SET_BIT(pool[j >> 3], j & 7); // 非质数标记为1
            }    
        }
    }
 
    *p = pool;
}
 
void main(void){
    int num;
    char *p;
 
    printf("请输入一个边界数: ");
    scanf("%d", &num);
 
    findPrime(num, &p);
    if(FALSE == Gguess(num, p)){
        printf("哥德巴赫猜想失败\n");
    }else{
        printf("哥德巴赫猜想成功了\n");
    }
}