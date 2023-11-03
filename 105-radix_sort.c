#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * getMaxInAr - Get the maximum value in an integer array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: The maximum value in the array, or -1 on error.
 */
int getMaxInAr(int *array, size_t size)
{
	size_t i;
	int max = 0;

	if (!array || !size)
		return (-1);

	for (i = 0, max = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * number_len - Calculate the length of an integer.
 * @n: The integer for which the length is calculated.
 *
 * Return: The length of the integer.
 */
int number_len(int n)
{
	unsigned int len, divisor;

	for (len = 0, divisor = 10; n; len++)
		n = n / divisor;
	return (len);
}

/**
 * count_sort - Sort an integer array using counting sort for a specific pass.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * @pass: The current pass (1, 10, 100, etc.).
 *
 * Return: 0 on success, -1 on error.
 */
int count_sort(int array[], size_t size, int pass);
int count_sort(int array[], size_t size, int pass)
{
	int size_i = (int)size;
	int *count = malloc(sizeof(int) * 10);
	int *tmp = malloc(sizeof(int) * size_i);
	int i, j;

	if (!pass || !array || !size)
	{
		free(count);
		free(tmp);
		return (-1);
	}
	for (j = 0; j < 10; j++)
		count[j] = 0;
	for (j = 0; j < size_i; j++)
		tmp[j] = 0;

	/* Initialize count array with zeros. */
	for (i = 0; i < size_i; i++)
	{
		++count[(array[i] / pass) % 10];
	}

	/* Update count array with prefix sums. */
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	/* Build the output array 'tmp'. */
	for (i = size_i - 1; i >= 0; i--)
	{
		tmp[--count[(array[i] / pass) % 10]] = array[i];
	}

	/* Copy 'tmp' back to 'array'. */
	for (i = 0; i < size_i; i++)
	{
		array[i] = tmp[i];
	}

	free(count);
	free(tmp);
	putchar(10);

	return (0);
}

/**
 * radix_sort - Sort an integer array using radix sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_n, pass;

	max_n = getMaxInAr(array, size);
	for (pass = 1; max_n / pass; pass *= 10)
	{
		count_sort(array, size, pass);
		print_array(array, size);
	}
}
