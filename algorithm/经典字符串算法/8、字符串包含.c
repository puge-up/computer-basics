#include<stdio.h>

typedef unsigned char boolean;

#define TRUE	1
#define FALSE	0
// 字符串单纯的包含,与位置没有关系
boolean isContain(char *str1, char *str2);

boolean isContain(char *str1, char *str2){
	char tmp[128] = {0};
	int i;
	int flag = 0;

	for(i = 0; str1[i]; i++){
		tmp[str1[i]]++;
	}
	for(i = 0; str2[i]; i++){
		if(tmp[str2[i]]){
			;
		}else{
			flag = 1;
			break;
		}
	}

	return flag == 0;
}

void main(void){
	char str1[80] = {0};
	char str2[80] = {0};
	boolean f;

	gets(str1);

	gets(str2);
	f = isContain(str1, str2);
	if(f){
		printf("str1包含str2\n");	
	}else{
		printf("str1不包含str2\n");
	}

}