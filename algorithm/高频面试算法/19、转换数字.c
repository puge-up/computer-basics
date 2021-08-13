#include<stdio.h>
#include<stdlib.h>

//"a1b2c3ef4"  <===> a=1,b=2,c=3,ef=4;
void prinT(char *str);
void prinT(char *str){
	int i;

	for(i = 0; str[i];){
		while(str[i] >= 'a' && str[i] <= 'z'){
			printf("%c", str[i]);
			i++;
		}
		printf(" = %d ", str[i]-'0');
		i++;
	}
}

void main(void){
	char str[80] = {0};

	printf("str : ");
	gets(str);
	prinT(str);
}