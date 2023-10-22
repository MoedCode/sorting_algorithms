#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: (int *) pointer to an integer array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		int smaller_value_found = 0, min_idx, min_value;

		min_value = array[i];

		for (j = i; j < size; j++)
		{

			if (array[j] < min_value)
			{

				smaller_value_found = 1;
				min_value = array[j];
				min_idx = j;
			}
		}

		if (smaller_value_found)
		{
			int tmp = array[i];

			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
