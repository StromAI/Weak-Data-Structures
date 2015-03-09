#include <stdio.h>
#include <stdlib.h>
#include "search_tree.h" 

int
main(int argc, char **argv)
{
	//SearchTree root = (SearchTree)malloc(sizeof(struct TreeNode));
	SearchTree root = NULL;
	root = MakeEmpty(root);
	root = Insert(1,root);
	root = Insert(3,root);
	root = Insert(2,root);
	root = Insert(14,root);
	root = Insert(11,root);
	root = Insert(7,root);
	root = Insert(10,root);
	root = Insert(13,root);
	Position node = FindMax(root);
	//printf("%d", node->Element);
	printf("%d\n",node->Element);
	node = FindMin(root);
	printf("%d\n",node->Element);
	root = Delete(node->Element,root);
	node = FindMin(root);
	printf("%d\n",node->Element);
	exit(0);
}