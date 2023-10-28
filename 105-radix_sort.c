#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
/**
 * int_to_string - shift and cast  given int to string  right  by adding 0
 * to he left number of zeros = max_len - length of the number
 * it uses  number_len function to calculate it
 * returns the string
 * @n:number to be shift
 * @max_len: number of shifting steps must >= number length
 * Return: (char*) string for a casted and shifted number,
 * (NULL) in cases error
 */
char *int_to_string(int n, int max_len) {

	int i;
	static char s[12];

	if (max_len <= 0 || max_len > 10) {
		fprintf(stderr, "Error: Invalid max_len %d\n", max_len);
		return NULL;
	}


	i = max_len - 1;

	s[max_len] = '\0';  /* Null-terminate the string.*/

	/* Fill the string with digits from right to left.*/
	while (i >= 0) {
		s[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}

	return s;
}

void radix_sort(int *array, size_t size)
{
	int max_num, max_num_len , size_i = (int)size, i, pntTst = 0,
	bucket[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char **output_array;

	max_num = getMaxInAr(array, size);
	max_num_len = number_len(max_num);
	output_array = malloc((size_i) * sizeof(char *));
	if (!output_array)
		return;
	/* assign output array index's*/
	for (i = 0; i < size_i; i++)
		output_array[i] = strdup(int_to_string(array[i],  max_num_len));
	output_array[i] = NULL;
	print_2Dstr_arr(output_array, size);

	for (i = 0; i < size_i; i++)
		bucket[output_array[i][1] - '0']++;
	print_array(bucket, 10);
	/* free out put array*/
	for (i = 0; i < size_i && pntTst; i++)
		if (output_array[i])
			free(output_array[i]);
	free(output_array);
}

