#include<stdio.h>

int binOf1(int n);
int binOf1(int n){
	int count = 0;
	
	while(n){
		count++;

		n = n & (n-1);
	}

	return count;
}

int main(void){
	int num;
	int count = 0;

	scanf("%d", &num);

	count = binOf1(num);
	printf("%d\n", count);
	return 0;
}