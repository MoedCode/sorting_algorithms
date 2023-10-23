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
 * shell_sort - sorts an array of integers in ascending order using the Shell sort algorithm
 * using the Knuth sequence
 * @array: pointer to array that will be sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, pass_count, i, j, is_swap = 1;

	if (!array || !size)
		return;

		 gap = size / 2;
	for (pass_count = 1; is_swap; pass_count++)
		{
			is_swap = 0;
			j = gap / pass_count;
			for(i = 0; j < size; i++, j++)
			{
				if (array[i] < array[j])
				{
					swap(&array[i], &array[j]);
					if (j == size - 1 && array[i - gap] < array[i] )
						swap(&array[i - gap], &array[i]);
					is_swap = 1;
				}
			}
			print_array(array, size);
		}

}