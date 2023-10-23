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
 * array_reverse - Reverse the order of elements in an integer array.
 * @array: The integer array to be reversed.
 * @size: The number of elements in the array.
 *
 * Description: This function takes an integer array and its size as input
 * and reverses the order of elements in the array.
 */
void array_reverse(int array[], size_t size)
{
	size_t start = 0;
	size_t end = size - 1;

	while (start < end)
	{
		int temp = array[start];

		array[start] = array[end];
		array[end] = temp;
		start++;
		end--;
	}
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
	size_t gap, pass_count, i, j, is_swap = 1;

	if (!array || !size)
		return;

	gap = size / 2;
	for (pass_count = 1; is_swap; pass_count++)
	{
		is_swap = 0;
		j = gap / pass_count;
		for (i = 0; j < size; i++, j++)
		{
			if (array[i] < array[j])
			{
				swap(&array[i], &array[j]);
				if (j == size - 1 && array[i - gap] < array[i])
					swap(&array[i - gap], &array[i]);
				is_swap = 1;
			}
		}
			print_array(array, size);
		}
		array_reverse(array, size);

}
