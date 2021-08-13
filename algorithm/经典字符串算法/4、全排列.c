#include<stdio.h>
#include<string.h>

void allPermutation(char *str, int from, int to);
void swap(char *a, char *b);

void swap(char *a, char *b){
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void allPermutation(char *str, int from, int to){
	int i;
	int j;

	if(to <= 1){
		return;
	}
	if(from == to){
		for(i = 0; i <= to; i++){
			printf("%c", str[i]);
		}
		printf("\n");
	}else{
		for(j = from; j <= to; j++){
			swap(&str[j], &str[from]);
			allPermutation(str, from+1, to);
			swap(&str[j], &str[from]);
		}
	}
}

void main(void){
	char str[80] = {0};
	int length;

	printf("str : ");
	gets(str);
	length = strlen(str);
	allPermutation(str, 0, length-1);
}
