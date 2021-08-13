#include<stdio.h>
#include<assert.h>

// 字符串的拷贝操作：连同0结束标志一起进行拷贝;
char *myStrcpy(char *strD, const char *strS);

char *myStrcpy(char *strD, const char *strS){
	char *ptmpD = strD;
	const char *ptmpS = strS;

	assert(ptmpD != NULL && ptmpS != NULL);
	while(*ptmpS){
		*ptmpD++ = *ptmpS++;
	}
	*ptmpD = 0;  // 连同0标志一同进行拷贝;

	return strD;	
}

int main(void){
	char s1[20] = "hello"; // 保证要拷贝的空间足够;
	char *s2 = "wor";

	printf("%s\n", myStrcpy(s1, s2));
	return 0;
}