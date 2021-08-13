#include"./binTree.h"
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void createTree(BinTreeNode *&root){
	Element data;

	cin>>data;

	if(data == '#'){
		root = NULL;
	}else{
		root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		root->data = data;
		createTree(root->left);
		createTree(root->right);
	}
}

void levelTree(BinTreeNode *root){
	queue<BinTreeNode *> qu;

	if(root){
		qu.push(root);
		while(!qu.empty()){
			BinTreeNode *p = qu.front();
			qu.pop();
			printf("%c", p->data);
			if(p->left){
				qu.push(p->left);
			}
			if(p->right){
				qu.push(p->right);
			}
		}
		cout<<endl;
	}
}		


void preTree(BinTreeNode *root){ // 非递归遍历,必须先将右孩子入栈,在将左孩子入栈,栈非空,即出栈访问;
	stack<BinTreeNode *> st;

	if(root){
		st.push(root);
		while(!st.empty()){
			BinTreeNode *p = st.top();
			st.pop();
			printf("%c", p->data);
			if(p->right){
				st.push(p->right);
			}
			if(p->left){
				st.push(p->left);
			}
		}

		printf("\n");
	}
}

void midTree(BinTreeNode *root){
	stack<BinTreeNode *> st;

	if(root){
		st.push(root);
		while(!st.empty()){
			while(root && root->left){
				st.push(root->left);
				root = root->left;
			}

			BinTreeNode *p = st.top();
			st.pop();
			printf("%c", p->data);

			if(p->right){
				root = p->right;
				st.push(root);
			}
		}
	}

	printf("\n");
}
/*
void lastTree(BinTreeNode *root){
	if(root){
		stack<FlagNode> st;
		FlagNode sn;
		do{
			while(root){
				sn.ptr = root;
				sn.tag = L;
				st.push(sn);
				root = root->left;
			}

			bool flag = true;
			while(flag && !st.empty()){
				sn = st.top();
				st.pop();
				switch(sn.tag){
					case R:
						 printf("%c", sn.ptr->data);
						 break;
					case L:
						 sn.tag = R;
						 st.push(sn);
						 flag = false;
						 root = sn.ptr->right;
						 break;
				}

			}

		}while(!st.empty());

		printf("\n");
	}
}
*/
void lastTree(BinTreeNode *root){
	FlagNode sn;
	stack<FlagNode> st;

	if(root){
		do{
			while(root){
				sn.ptr = root;
				sn.tag = L;
				st.push(sn);
				root = root->left;
			}

			bool flag = true;
			while(flag && !st.empty()){
				sn = st.top();
				st.pop();
				switch(sn.tag){
					case L:
						 sn.tag = R;
						 st.push(sn);
						 flag = false;
						 root = sn.ptr->right;
						 break;
					case R:
						 printf("%c", sn.ptr->data);
						 break;
				}
			}
		
		}while(!st.empty());
		printf("\n");
	}
}

int main(void){
	BinTreeNode *root = NULL;
	createTree(root);
	//levelTree(root);
	//preTree(root);
	midTree(root);
	//lastTree(root);

	return 0;
}

