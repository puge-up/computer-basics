#include<stdio.h>
#include<string.h>

// 时间复杂度为：O(n),空间复杂度为：O(1);
// abcdefg----->cdefgab
void revStr(char *str, int length);

void revStr(char *str, int length){
	char tmp;
	
	if(length > 1){
		tmp = str[0];
		str[0] = str[length-1];
		str[length-1] = tmp;
		revStr(str+1, length-2);
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
	revStr(str, number);
	revStr(str+number, strLen-number); 
	revStr(str, strLen);
	printf("%s\n", str);
}
