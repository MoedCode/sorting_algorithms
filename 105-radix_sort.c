#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * number_len - function that gets the length of a given numbers
 *
 * parameters:
 * @n: number that it's length wanted to be calculated
 *
 * Return: the given number length
 */

 int number_len(int n)
{
	unsigned int len, divisor;

	for(len = 0, divisor = 10; n; len++)
		n = n / divisor;
	return (len);
}

char *int2str(int n, int max_len)
{
	int len = number_len(n), divisor = 10, i, j, lenDif;
	static char s[12];
	if (!max_len || max_len < len || max_len + len > 10)
	{
		fprintf(stderr, "Err num len[%d], max_len[%d]", len, max_len);
		return (NULL);
	}


	if ( max_len - len > 0)
	{
		lenDif = max_len - len;
		for (j = 0; j < lenDif ; j++)
			s[j] = '0';
	}
	else
		j = 0;
	for(i = j; n; i++)
	{
		s[i] = n % divisor + '0';
		n = n / divisor;
	}
	s[i] = '\0';
	return s;
}
void radix_sort(int *array, size_t size)
{
	int max_int, max_int_len , size_i = (int)size, i;
	char **output_array;



	max_int = getMaxInAr(array, size);
	max_int_len = number_len(max_int);

	output_array = malloc((size_i) * sizeof(char *));
	if (!output_array)
		return;


	for (i = 0; i < size_i; i++)
	{
		output_array[i] = strdup(int2str(array[i],  max_int_len));
		printf("[%i]=%s, ", i, int2str(array[i],  max_int_len));
		if (i == (size_i - 1))
			puts("\n");
	}
	output_array[i] = NULL;
	for (i = 0; i < size_i; i++)
		if (output_array[i])
			printf("[%i]=%s, ", i, output_array[i]);

	for (i = 0; i < size_i; i++)
		if (output_array[i])
			free(output_array[i]);
	putchar(10);
	free(output_array);

}