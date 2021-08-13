#include<stdio.h>
#include<string.h>

#define TRUE	1
#define FALSE	0

typedef unsigned char boolean;

boolean isPalindrome(char *str);
boolean isPalindrome(char *str){
	char *front = str;
	char *back;

	if(NULL == str){
		return FALSE;
	}
	int length = strlen(str);
	back = str+length-1;

	while(front < back){
		if(*front == *back){
			front++;
			back--;
		}else{
			return FALSE;
		}
	}

	return TRUE;
}

void main(void){
	char str[80] = {0};
	boolean flag;

	printf("str : ");
	gets(str);
	flag = isPalindrome(str);
	if(flag){
		printf("是回文\n");
	}else{
		printf("不是回文\n");
	}

}