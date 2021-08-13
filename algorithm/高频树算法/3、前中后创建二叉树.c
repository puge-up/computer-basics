#include"./binTree.h"
#include<string.h>

void preMidTree(BinTreeNode **root, const char *VLR, const char *LVR, int n){
	if(n == 0){
		root = NULL;
		return;
	}else{
		int k = 0;

		while(VLR[0] != LVR[k]){
			k++;
		}
		(*root) = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		(*root)->data = VLR[0];

		preMidTree(&(*root)->left, VLR+1, LVR, k);
		preMidTree(&(*root)->right, VLR+k+1, LVR+k+1, n-k-1);
	}
}
void midLastTree(BinTreeNode **root, char *LVR, char *LRV, int n){
	if(n == 0){
		*root = NULL;
		return;
	}else{
		int k = 0;
		while(LVR[k] != LRV[n-1]){
			k++;
		}

		(*root) = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		(*root)->data = LRV[n-1];
		midLastTree(&(*root)->right, LVR+k+1, LRV+k, n-k-1);
		midLastTree(&(*root)->left, LVR, LRV, k);

	}
}

void showTree(BinTreeNode *root){
	if(root){
		printf("%c", root->data);
		showTree(root->left);
		showTree(root->right);
	}
}

int main(void){
	char *VLR = "ABCDEFGH";
	char *LVR = "CBEDFAGH";
	char *LRV = "CEFDBHGA";
	BinTreeNode *root = NULL;

	//pareMidTree(&root, VLR, LVR, strlen(VLR));
	midLastTree(&root, LVR, LRV, strlen(LVR));
	showTree(root);
	printf("\n");

	return 0;
}
