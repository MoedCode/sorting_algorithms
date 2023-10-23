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
 #include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
