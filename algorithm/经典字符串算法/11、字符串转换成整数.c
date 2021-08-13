#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define TRUE	1
#define FALSE	0
#define MAX_NUM	2147483647	
#define MIN_NUM 2147483648

char islegal = TRUE;  // 设置一个全局变量,用来判断输入的是否合法;

int strToInt(char *str);
int strToInt(char *str){
	int sign = 1;   // 代表正数
	int i;
	unsigned int num = 0;  // 要保证num不能溢出,在做比较的时候
    
    // int的范围:-2147483648---2147483647
    // unsigned int的范围：0-4294967296,此时在保证不溢出的情况下,对数值进行判断;

	if(NULL == str){  // 判断输入是否为空
		islegal = FALSE;
		return -1;
	}

	while(isspace(*str)){
		++str;
	}
	if(*str == '+' || *str == '-'){
		if(*str++ == '-'){
			sign = -1;
		}
		if(*str == 0){  // 字符串只输入了一个+/-都是非法输入;
			islegal = FALSE;
			return -1;
		}
	}
	
	for(i = 0; str[i]; i++){
		if(isdigit(str[i])){
			;
		}else{
			islegal = FALSE;
			return -1;
		}
	}

	while(isdigit(*str)){  // 判断是否为0-9,是的话返回非0,不是返回0
		// 此时的难点是判断溢出问题;
		num = num * 10 + *str - '0';
		++str;

		if(sign == 1 && num > MAX_NUM){
			islegal = FALSE;
			return -1;			
		}
		if(sign == -1 && num > MIN_NUM){
			islegal = FALSE;
			return -1;				
		}
	}
	return (sign > 0 ? (int)num : (int)-num);
}

void main(void){
	char str[80] = {0};
	int num;

	printf("str : ");
	gets(str);
	num = strToInt(str);
	if(islegal == TRUE){
		printf("%d\n", num);
	}else{
		printf("输入的是非法的\n");
	}
}