#include<iostream>
#include<stack>
using namespace std;

class Test{
public:
	void push_(int data){
		st1.push(data);
	}
	int pop_(){
		int tmp;

		if(st2.empty()){
			while(!st1.empty()){
				int element = st1.top();
				st1.pop();
				st2.push(element);
			}
		}

		if(!st2.empty()){
			tmp = st2.top();
			st2.pop();
		}

		return tmp;

	}

private:
	stack<int> st1;
	stack<int> st2;
};

int main(void){
	Test t;
	int num;

	t.push_(6);
	t.push_(5);
	t.push_(4);
	t.push_(3);
	t.push_(2);
	t.push_(1);

	for(int i = 0; i < 6; i++){
		num = t.pop_();
		cout<<num<<" ";
	}
	cout<<endl;

	return 0;
}
