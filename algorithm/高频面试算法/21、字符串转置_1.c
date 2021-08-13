#include<stdio.h>
#include<string.h>
 
void revStr(char *str, char *tmp);
void revStr(char *str, char *tmp){
    if(str == NULL || tmp == NULL){
        printf("有为空的,逆序不能进行\n");
        return;
    }   
    if(*str == 0){ 
        return;
    }   
    revStr(str+1, tmp); //用栈实现字符串的逆序,先进后出;
 
    strncat(tmp, str, 1); 
}
 
int main(void){
    char str1[80] = "abcdefghijkl";
    char tmp[80];
 
    printf("逆序前:%s\n", str1);
    revStr(str1, tmp);
    printf("逆序后:%s\n", tmp);
}