#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define NOT_FOUND	-1;

void KMPnext(char *substr, int *next);
int KMP(char *str, char *substr);
int KMP(char *str, char *substr){
	int *next;
	int i = 0;
	int j = 0;
//abcdefabcdefgabcdefgabcd
//bcdefg
	next = (int *)calloc(sizeof(int), strlen(substr));
	KMPnext(substr, next);
	while(str[i]){
		for(j = next[j]; substr[j] && str[i] == substr[j]; i++, j++){
			;
		}

		if(substr[j] == 0){
			return i-j;
		}
		if(j == 0){
			i++;
		}
	}
	free(next);

	return NOT_FOUND;

}

void KMPnext(char *substr, int *next){
	int index;
	int j;

	for(index = 2; substr[index]; index++){
		for(j = index-1; j && substr[next[j]] != substr[index-1]; j = next[j]){
			;
		}

		next[index] = j ? next[j]+1 : 0;
	}
}

void main(void){
	char substr[80] = {0};
	char str[80] = {0};
	int index;

	printf("str : ");
	scanf("%s", str);
	printf("substr : ");
	scanf("%s", substr);
	index = KMP(str, substr);
	printf("%d\n", index);	
}