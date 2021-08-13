#include<stdio.h>

void main(void){
	char str[] = "abacdefabcde";
	char alpha[128] = {0};  // 辅助空间，桶的思想
	char res[80] = {0};  // 存放去重后的结果字符串
	int i;
	int t = 0;

	for(i = 0; str[i]; i++){
		if(alpha[str[i]] == 0){
			res[t++] = str[i];
			alpha[str[i]]++;
		}
	}

	for(i = 0; i < t; i++){
		printf("%c", res[i]);
	}
	printf("\n");

}