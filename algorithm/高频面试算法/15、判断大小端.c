#include<stdio.h>

typedef unsigned char boolean;

#define TRUE	1
#define FALSE	0


boolean checkSystem();
boolean checkSystem(){
	union{
		int a;
		char b;
	}t;

	t.a = 1;
	return t.b == 1;
}

void main(void){
	boolean flag;
	flag = checkSystem();
	if(flag){
		printf("This is small\n");
	}else{
		printf("This is big\n");
	}

}