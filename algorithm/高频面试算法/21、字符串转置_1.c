#include<stdio.h>
#include<string.h>
 
void revStr(char *str, char *tmp);
void revStr(char *str, char *tmp){
    if(str == NULL || tmp == NULL){
        printf("ÓÐÎª¿ÕµÄ,ÄæÐò²»ÄÜ½øÐÐ\n");
        return;
    }   
    if(*str == 0){ 
        return;
    }   
    revStr(str+1, tmp); //ÓÃÕ»ÊµÏÖ×Ö·û´®µÄÄæÐò,ÏÈ½øºó³ö;
 
    strncat(tmp, str, 1); 
}
 
int main(void){
    char str1[80] = "abcdefghijkl";
    char tmp[80];
 
    printf("ÄæÐòÇ°:%s\n", str1);
    revStr(str1, tmp);
    printf("ÄæÐòºó:%s\n", tmp);
}