#include<stdio.h>
#include<malloc.h>
#include<string.h>

void KMPnext(const char *sub, int *next);
int findSubIndex(const char *source, const char *sub);
/*
aaaaaaaabaaa
aaabaa
*/
int findSubIndex(const char *source, const char *sub){
	int i = 0;
	int j = 0;
	int *next;
	int len = strlen(source);

	next = (int *)calloc(sizeof(int), len);
	KMPnext(sub, next);

	while(source[i]){
		for(j = next[j]; sub[j] && source[i] == sub[j]; i++, j++){
			;
		}
		if(sub[j] == 0){
			return i-j;
		}else if(j == 0){
			i++;
		}
	}
	free(next);
	return -1;
}

void KMPnext(const char *sub, int *next){
	int index;
	int j;

	for(index = 2; sub[index]; index++){
		for(j = index-1; j && sub[next[j]] != sub[index-1]; j = next[j]){
			;
		}
	 	next[index] = j ? next[j]+1 : 0; // 给当前的next数组赋值！！！
	}
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