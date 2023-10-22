#include "sort.h"
#include <stddef.h>
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
		return;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
/**
 * selection_sort - sorts array using section algorithm
 * @array: pointer to array
 * @size: array size
 * Return: void
 */
void selection_sort_1(int *array, size_t size)
{
	size_t i, is_swap;

	if (!array || !size)
		return;

while (is_swap)

{
	is_swap = 0;
	for (i = 0; i < size - 1; ++i)
	{
		if (array[i] > array[i + 1])
		{
			swap(&array[i], &array[i + 1]);
			is_swap = 1;
		}
	}
	print_array(array,  size);
}
}
