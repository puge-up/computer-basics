#include<stdio.h>
#include<assert.h>

// 假如不允许使用变量进行计数,此时就得进行递归计算,是一种倒着加回去的思想;
size_t myStrlen_1(const char *str);
size_t myStrlen_1(const char *str){
	assert(str != NULL);	

	if(*str == 0){
		return 0;
	}else{
		return myStrlen_1(str+1)+1;
	}
}

//typedef unsigned int size_t;  
size_t myStrlen(const char *str);
size_t myStrlen(const char *str){
	const char *ptmp = str;  // 1、对参数进行保护机制
	size_t count = 0;		

	assert(str != NULL);  // 2、对参数的合法性进行断言
	while(*ptmp++){  // 此处的++运算符的优先级大于*,但是是后++,所以先进行指向运算，在进行++;
		count++;
	}

	return count;
}

int main(void){
	char *str = "Hello C";

	printf("%d\n", myStrlen_1(str));
	return 0;
}