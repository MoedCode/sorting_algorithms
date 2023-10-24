#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * getMaxInAr - Get the Max value in the Array
 *
 * @array: pointer to array
 * @size: size of array
 * Return: positive (int) which is max, (-1) on error
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
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: pointer to array
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int max = getMaxInAr(array, size),
	 *count_arr, *output_arr, j, i, sizei = (int)size;

	if (array == NULL || size < 2)
		return;
	/* allocating count_arr and output_arr*/
	count_arr = malloc((max + 1) *  sizeof(int));
	if (!count_arr)
		return;
	output_arr = malloc((sizei + 1) * sizeof(int));
	if(!output_arr)
		return;
	/* set all index's to 0 */
	for ( i = 0; i < max + 1; i++)
		count_arr[i] = 0;
	for (i = 0; i < sizei; i++)
		count_arr[array[i]]++;

	/* accumulating */
	for ( i = 0; (int)i < max; i++)
		count_arr[i] += count_arr[i -1];

	print_array(count_arr, max + 1);

	for (j = sizei -1; j >= 0; j--)
	{
		output_arr[count_arr[array[j]] - 1] = array[j];
		count_arr[array[j]]--;

	}
	for (i = 0; i <  sizei; i++)
		array[i] = output_arr[i];
	free(count_arr);
	free(output_arr);

}
