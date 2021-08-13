#include<stdio.h>
 
int sum(int n){ 
    if(n == 0){ 
        return 0;
    }   
 
    return n+sum(n-1);
}
 
int main(void){
    int number;
    int n;
 
    scanf("%d", &number);
    n = sum(number);
    printf("%d\n", n); 
 
    return 0;
}