#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void twoSum(vector<int> &v1, int sum);

void twoSum(vector<int> &v1, int sum){
	int begin = 0;
	int end = v1.size()-1;

	while(begin < end){
		if(v1[begin] + v1[end] == sum){
			printf("%d %d\n", v1[begin], v1[end]);
			break;
		}else if(v1[begin] + v1[end] < sum){
			begin++;
		}else{
			end--;
		}
	}

	if(begin == end){
		printf("和为定值 = %d\n", sum);
	}
}

void main(void){
	int a[] = {3, 5, 1, 8, 4, 0,};
	int count = sizeof(a)/sizeof(int);
	int i;
	vector<int> v1;

	for(i = 0; i < count; i++){
		v1.push_back(a[i]);
	}
	sort(v1.begin(), v1.end(), less<int>());

	twoSum(v1, 9);

}