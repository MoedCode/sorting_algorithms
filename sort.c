#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * swap - swaps  tow integers
 * @x: pointer to  first integers
 * @y: pointer to  second integers
 * Return: void
*/
void swap(int *x, int *y)
{
	int tmp;

	if (x == NULL || y == NULL)
	{
		x == NULL && fprintf(stderr, "X is nill ");
		y == NULL && fprintf(stderr, "y is nill ");
		return;
	}
	tmp = *x;
	*x = *y;
	*y = tmp;

}

