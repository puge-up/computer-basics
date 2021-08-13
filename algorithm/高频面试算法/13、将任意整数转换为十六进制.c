#include<stdio.h>
 
void digui(int n); 
 
void digui(int n){ 
    int c;
    c = n%16;
 
    if(n > 0){ 
        digui(n/16);
        if(c >= 10){
            printf("%c", c-10+'A');
        }else{
            printf("%d", c); 
        }   
    }   
}
int main(void){
    int n;
 
    scanf("%d", &n);
    digui(n);
    printf("\n");
 
    return 0;
}