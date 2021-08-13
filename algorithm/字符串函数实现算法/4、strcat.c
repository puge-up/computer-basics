#include<stdio.h>
#include<assert.h>

char *myStrcat(char *strD, const char *strS);

char *myStrcat(char *strD, const char *strS){  // 返回的是第一个字符串的地址:s1 += s2;
	char *ptmpD = strD;   // 1、对原参数的保护机制
	const char *ptmpS = strS;

	assert(strD != NULL && strS != NULL); // 断言,防止出错;

	while(*ptmpD){  // 目标的先走到第一个字符串的末尾
		ptmpD++;
	}

	while(*ptmpS){ // 原的不为空,将原的一个一个字符的拷到目标的字符串中
		*ptmpD++ = *ptmpS++;
	}
	*ptmpD = 0; // 最后一个字符的空间必须赋值为0；

	return strD;
}

int main(void){
	char s1[20] = "hello";  // 申请足够的空间够连接的;
	char *s2 = "world";

	printf("%s\n", myStrcat(s1, s2));
	return 0;
}