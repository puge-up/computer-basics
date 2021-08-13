#include<stdio.h>
#include<string.h>
 
int strLen(char *str);
int strLen(char *str){
    if(*str == 0){ 
        return;
    }   
 
    return 1+strLen(str+1);
}
 
int main(void){
    char str[80];
    int len;
 
    gets(str);
    len = strLen(str);
    printf("%d\n", len);
 
}