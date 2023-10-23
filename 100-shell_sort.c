#include "sort.h"
#include <stddef.h>
#include <stdio.h>
/**
 * swap - swaps two integers
 * @x: pointer to the first integer
 * @y: pointer to the second integer
 * Return: void
 */
void swap(int *x, int *y)
{
	int tmp;

	if (x == NULL || y == NULL)
		return;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm using the Knuth sequence
 * @array: pointer to array that will be sort
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;
	/*generat knuth interval*/
	gap = 1;
	for (; gap < size / 3; gap = gap * 3 + 1)
		;


	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
