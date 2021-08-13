#include<stdio.h> 
#include<assert.h>

void removeBlank(char *str);
void removeBlank(char *str){
	char *cur = str;
	char *pre = str;
	assert(str != NULL);

	while(*cur != 0){
		if(*cur != ' '){
			*pre++ = *cur;	
		}
		cur++;
	}
	*pre = 0;
}

void main(void){
	char str[] = "  ABCD  EFG  HI JKL ";
	removeBlank(str);
	printf("%s\n", str);

}