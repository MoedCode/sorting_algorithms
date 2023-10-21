#include "sort.h"
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
 * bubble_sort - sorts a given array of integers  using bubble sort algorithm
 * @array: (int *) pointer to an integer array to sort
 * @size: size of the array
 * Return: (void)
 */

#include "sort.h"
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		int sorted = 0;

		for (j = 0; j < size; j++)
		{
			if (j + 1 < size && array[j] > array[j + 1])
			{
				int tmp = array[j + 1];

				array[j + 1] = array[j];
				array[j] = tmp;

				sorted = 1;
				print_array(array, size);
			}
		}

		if (sorted == 0)
			return;
	}
}
