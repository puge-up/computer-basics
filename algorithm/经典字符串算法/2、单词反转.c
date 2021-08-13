#include<stdio.h>
#include<string.h>
#include<ctype.h>


void revStr(char *str, int from, int to);
void finalRev(char *str);

void finalRev(char *str){
	int from = 0;
	int to = 0;

	while(str[to]){
		while(isalpha(str[to])){
			to++;
		}
		revStr(str, from, to-1);
		while(isspace(str[to])){
			to++;
		}
		from = to;
	}
}

void revStr(char *str, int from, int to){
	char tmp;

	while(from < to){
		tmp = str[from];
		str[from++] = str[to];
		str[to--] = tmp;
	}
}

void main(void){
	char str[80];
	int strLen;
	int count = 0;
	int i = 0;

	// gets在接收字符串时,可以接收空格,中间的空格都将被接收下来;
	// scanf在接收字符串时,遇到空格、回车和Tab键都会认为输入结束，所有它不能接收空格;
	printf("请输入字符串: \n");
	gets(str);
	strLen = strlen(str);
	revStr(str, 0, strLen-1);
	finalRev(str);

	puts(str);	
}