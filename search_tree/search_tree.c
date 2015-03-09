#include <stdio.h>
#include <malloc.h>
#include "search_tree.h"

SearchTree 
MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position
Find(ElementType X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	else if(X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}	

Position
FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position
FindMax(SearchTree T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}

SearchTree
Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if (T == NULL)
		{
			printf("Out of speace");
			return NULL;
		}
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)	
			T->Left = Insert(X, T->Left);
	else if (X > T->Element)
			T->Right = Insert(X, T->Right);
	/* Else X is in the tree already; We do nothing */

	return T;
}

SearchTree
Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
	{
		printf("Element Not found");
		return NULL;
	}
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else if (T->Left && T->Right)
	{
		/*	Replace with smallest in right subtree */
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else 	/* one or zero child*/
	{
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}