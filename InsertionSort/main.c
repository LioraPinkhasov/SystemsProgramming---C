#include <stdio.h>
#include <stdlib.h>
#include "InsertionSort.h"
#define MAX 50

extern int  size;

int main()
{
	setbuf(stdout,NULL);

	int* RandomNumberArr = (int*)malloc(size * sizeof(int));
	if(RandomNumberArr == NULL){
		printf("Could not allocate memory\n");
		return 0;
	}

	genrate_arr(RandomNumberArr);

	printf("this is your array: ");
	print_arr(RandomNumberArr);
	shift_element(RandomNumberArr + 1, 2);

	insertsort(RandomNumberArr, size);

	printf("now your array looks like this:\n");
	print_arr(RandomNumberArr);

	free(RandomNumberArr);

	return 0;
}
