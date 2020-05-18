#include "InsertionSort.h"
#include <stdio.h>
#include <stdlib.h>

int size = 50;

void shift_element(int* RandomNumberArr, int shift)
{
	int i=0;
	for (i = shift; i > 0; i--)
	{
		*(RandomNumberArr + i) = *(RandomNumberArr + i - 1);
	}
}

void genrate_random_arr(int* RandomNumberArr, int count)
{
	int i = 0;

	for (i=0;i<size;i++)
	{
		int tmp = rand() % 100;
		*(RandomNumberArr + i) = tmp;
	}
}

void genrate_arr(int* RandomNumberArr)
{
	int i = 0;
	printf("plese enter 50 numbers into our array: ");

	for (i=0;i<size;i++)
	{
		scanf("%d",&RandomNumberArr[i]);
	}
}

void print_arr (int* RandomNumberArr)
{
	int i=0;
	for (i=0;i<size;i++)
	{
		printf(" %d ",*(RandomNumberArr + i));
	}
	printf("\n");
}

void insertsort(int* RandomNumberArr ,int size)
{
	for (int i = 0; i < size - 1; i++)
	{
	    for (int j = i + 1; j > 0 && *(RandomNumberArr + j - 1) > *(RandomNumberArr + j); j--) {
	    	int tmp = *(RandomNumberArr + j);
	    	shift_element(RandomNumberArr + j - 1, 1);
	    	*(RandomNumberArr + j - 1) = tmp;
		}
	}
}
