#include<stdio.h>
 
int fibonacci(int n);
 
int fibonacci(int n){
    if(n <= 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
 
    return fibonacci(n-1)+fibonacci(n-2);
}
 
void main(void){
    int number;
    int value;
 
    printf("请输入第几个斐波那契数：");
    scanf("%d", &number);
 
    value = fibonacci(number);
    printf("%d\n", value);
}