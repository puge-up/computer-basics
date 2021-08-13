#include<stdio.h>

void main(void){
	char str[] = "abacdefabcde";
	char alpha[128] = {0};  //¸¨Öú¿Õ¼ä£¬Í°µÄË¼Ïë
	char res[80] = {0};  //´æ·ÅÈ¥ÖØºóµÄ½á¹û×Ö·û´®
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