#include <stdio.h>
#include <stdlib.h>

int
BinSearchRecursion(int *arry, int low, int high, int key)
{
	if (low <= high)
	{
		int mid = (low+high)/2;
		if (key == *(arry+mid))
			return mid;
		if (key  < *(arry+mid))
			return BinSearchRecursion(arry,low,mid-1,key);
		else
			return BinSearchRecursion(arry,mid+1,high,key);
	}
	else
		return -1;
}

int
BinSearchLoop(int *arry, int sizeOfArray, int key)
{
	int low = 0,high = sizeOfArray-1;
	int mid;
	while (low <= high)
	{
		mid = (low+high)/2;
		if (key == *(arry+mid))
			return mid;
		if (key < *(arry+mid))
			high = mid-1;
		else
			low = mid + 1;
	}
	return -1;
}



int
main (int argc, char** argv)
{
	int i;
	int arry[100];
	for (i = 0; i < 100; i++)
	{
		arry[i] = i;
	}
	int a = BinSearchRecursion(arry,0,99,20);
	int b = BinSearchLoop(arry,100,20);

	printf("%d%d",a,b);
	exit(0);
} 
