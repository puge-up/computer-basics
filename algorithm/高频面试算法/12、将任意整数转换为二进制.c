#include<stdio.h>
 
void digui(int n){ 
    int c;
    c = n%2;
 
    if(n > 0){ 
        digui(n/2);
        printf("%d", c); 
    }   
}
 
int main(void){
    int n; 
 
    scanf("%d", &n);
    digui(n);
    printf("\n");
 
    return 0;
}