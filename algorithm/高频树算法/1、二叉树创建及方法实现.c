#include"./binTree.h"

// 前序创建二叉树

void createbintree(BinTreeNode **root){
	Element data;

	scanf("%c", &data);

	if(data == '#'){
		*root = NULL;
	}else{
		*root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		(*root)->data = data;
		createbintree(&(*root)->left);
		createbintree(&(*root)->right);
	}
}

void showbintree(BinTreeNode *root){
	if(root != NULL){
		printf("%c", root->data);
		showbintree(root->left);
		showbintree(root->right);
	}

}

void createbintree_1(BinTreeNode **root, char **str){
	if(**str == '#'){
		*root = NULL;
	}else{
		(*root) = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		(*root)->data = **str;
		char *tmp = ++*str;
		createbintree_1(&(*root)->left, &tmp);
		char *tmp1 = ++*str;
		createbintree_1(&(*root)->right, &tmp1);
	}
}

int size(BinTreeNode *root){ // 左子树+右子树+1
	if(root == NULL){
		return 0;
	}else{
		return size(root->left) + size(root->right) + 1;
	}
}

int heigh(BinTreeNode *root){
	if(root == NULL){
		return 0;
	}else{
		int leftheigh = heigh(root->left);
		int rightheigh = heigh(root->right);
		return (leftheigh > rightheigh ? leftheigh : rightheigh) + 1;
	}
}
BinTreeNode *search(BinTreeNode *root, Element key){
	if(root == NULL){
		return NULL;
	}

	if(root->data == key){
		return root;
	}

	BinTreeNode *p = search(root->left, key);
	if(p){  // p不为空,说明找到了
		return p;
	}
	return search(root->right, key);
}

BinTreeNode* Parent(BinTreeNode *root, BinTreeNode *p){
	if(root == NULL || p == NULL){
		return NULL;
	}
	if(root->left == p || root->right == p){
		return root;
	}
	BinTreeNode *q = Parent(root->left, p);
	if(q){
		return q;
	}

	return Parent(root->right, p);
}

BinTreeNode* left(BinTreeNode *root){
	if(root){
		return root->left;
	}

	return NULL;
}

BinTreeNode* right(BinTreeNode *root){
	if(root){
		return root->right;
	}

	return NULL;
}
boolean bintreeempty(BinTreeNode *root){
	return root == NULL;
}

void copy(BinTreeNode *r1, BinTreeNode **r2){
	if(r1 == NULL){
		*r2 = NULL;
	}else{
		(*r2) = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		(*r2)->data = r1->data;
		copy(r1->left, &(*r2)->left);
		copy(r1->right, &(*r2)->right);
	}
}

void clear(BinTreeNode **root){
	if(*root != NULL){
		clear(&(*root)->left);
		clear(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}

int main(void){
	BinTreeNode *root = NULL;
	char *str = "abc####";

	createbintree(&root);
	//createbintree_1(&root, &str);
	showbintree(root);
	printf("\n");

	printf("size = %d\n", size(root));
	printf("heigh = %d\n", heigh(root));
	BinTreeNode *p = search(root, 'C');
	if(p == NULL){
		printf("no found\n");
	}else{
		printf("found\n");
	}
	BinTreeNode *parent = Parent(root, p); // 查找节点的地址
	if(parent == NULL){
		printf("no found\n");
	}else{
		printf("found\n");
	}
	BinTreeNode *r2 = NULL;
	copy(root, &r2);
	showbintree(r2);
	printf("\n");

	clear(&root);
	return 0;

}