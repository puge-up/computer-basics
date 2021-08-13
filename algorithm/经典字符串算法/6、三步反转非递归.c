#include<stdio.h>
#include<string.h>

void revStr(char *str, int from, int to);

void revStr(char *str, int from, int to){
	 int tmp;

	 while(from < to){
		tmp = str[from];
		str[from++] = str[to];
		str[to--] = tmp;
	 }
}

void main(void){
	char str[80];
	int number;
	int strLen;

	printf("请输入字符串: \n");
	gets(str);
	strLen = strlen(str);
	printf("请输入要放到后面字符串的个数: ");
	scanf("%d", &number);
	revStr(str, 0, number-1);
	revStr(str, number, strLen-1);
	revStr(str, 0, strLen-1);
	printf("%s\n", str);

}
