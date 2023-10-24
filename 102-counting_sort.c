#include "sort.h"
#include <stddef.h>
#include <stdlib.h>

 int getMaxInAr(int *array, size_t size)
{
	size_t i;
	int max = 0;

	if (!array || !size)
		return(-1);

	for ( i = 0, max = 0; i < size; i++)
	{
		if (max < array[i])
				max = array[i];
	}
	return (max);
}
void counting_sort(int *array, size_t size)
{
	int max = getMaxInAr(array, size),
	*count_arr, i, k = 0;
	size_t  j;
	count_arr = malloc(sizeof(int) * max);


	for (i = 0; i < max; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (array[j] == i)
					count_arr[i]++;
			}

		}
	for (i = 0; i < max; i++)
	{
		if (count_arr[i] != 0)
		{
			array[k] = i;
			k++;
		}
	}

	print_array(count_arr, max);
	printf("maix is [%d]", max);
	free(count_arr);


}