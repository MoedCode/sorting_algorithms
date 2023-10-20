#include "sort.h"
#include <stddef.h>
#include <stdio.h>


void swap(int *x, int *y)
{
	if(x == NULL || y == NULL)
	{
	   x == NULL && fprintf(stderr, "X is nill ");
	   y == NULL && fprintf(stderr, "y is nill ");
	   return;
	}
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;

}


/*
int sort_int_arr(int arr[], size_t size)
{
	int is_swp = 0;
	size_t i;
	for ( i = 0; i < size - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(&arr[i], &arr[i+1]);
			is_swp = 1;
		}
		else
			is_swp = 0;
	}
	if (is_swp)
		sort_int_arr(arr, size);

}
*/