#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define Element	char

typedef struct BinTreeNode{
	Element data;
	struct BinTreeNode *left;
	struct BinTreeNode *right;
}BinTreeNode;

typedef enum{L, R} Tag;
typedef struct FlagNode{
	BinTreeNode *ptr;
	Tag			tag;
}FlagNode;

typedef FlagNode newElement;

typedef unsigned char boolean;

#define TRUE	1
#define FALSE	0

#endif