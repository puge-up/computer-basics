#include<stdio.h>
#include<string.h>

// 时间复杂度为:O(m * n)
int findSubIndex(const char *source, const char *sub);

int findSubIndex(const char *source, const char *sub){
	int i;
	int j;
	int len = strlen(source) - strlen(sub);

	for(i = 0; i <= len; i++){
		for(j = 0; sub[j] && source[i+j] == sub[j]; j++){
			;
		}
		if(sub[j] == 0){
			return i;
		}
	}

	return -1;
}

void main(void){
	char source[80];
	char sub[80];

	puts("请输入原串: ");
	gets(source);
	puts("请输入子串: ");
	gets(sub);

	printf("%d\n", findSubIndex(source, sub));
}