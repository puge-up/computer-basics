#include<stdio.h>
#include<string.h>
 
void strrev_1(char *str, int length);
void strrev_1(char *str, int length){
    char tmp; 
 
    if(length > 1){ 
        tmp = *str;
        *str = *(str+length-1);
        *(str+length-1) = tmp;
        strrev_1(str+1, length-2);
    }   
     
}   
int main(void){
    char str[] = "abcdefg"; 
    int length = strlen(str);
 
    printf("转置前: %s\n", str);
    strrev_1(str, length);
    printf("转置后: %s\n", str);
 
    return 0;
}