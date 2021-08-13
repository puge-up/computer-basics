#include<stdio.h>
 
int fibonacci(int n);
 
int fibonacci(int n){
    int firstNumber = 0;
    int secondNumber = 1;
    int finNumber;
    int i = 2;
 
    if(n == 1){
        return firstNumber; 
    }
    if(n == 2){
        return secondNumber;
    }
 
    for(i = 3; i <= n; i++){
        finNumber = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = finNumber;
    }
 
    return finNumber;
}
 
void main(void){
    int number;
    int value;
 
    printf("请输入第几个斐波那契数：");
    scanf("%d", &number);
 
    value = fibonacci(number);
    printf("%d\n", value);
}