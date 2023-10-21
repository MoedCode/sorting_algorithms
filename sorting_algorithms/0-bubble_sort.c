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
			if (array[j] > array[i])
			{
				int tmp = array[i];

				array[i] = array[j];
				array[j] = tmp;

				sorted = 1;
				print_array(array, size);
			}
		}
		printf("************************\n");

		if (sorted == 0)
			return;
	}
}
