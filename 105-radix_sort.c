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
	int max_num, max_num_len , size_i = (int)size, i ,j,
	*bucket = calloc(sizeof(int), 10), LSD, LSDVal, pass, LSDIdx,
	*output_arr = calloc(sizeof(int), size_i);
	char **shifted_arr;

	_print_array(array, size);
	max_num = getMaxInAr(array, size);
	max_num_len = number_len(max_num);
	LSDIdx = max_num_len - 1;
	shifted_arr = malloc((size_i) * sizeof(char *));
	if (!shifted_arr)
		return;

	/* assign output array index's*/
	for (i = 0; i < size_i; i++)
		shifted_arr[i] = strdup(int_to_string(array[i],  max_num_len));
	shifted_arr[i] = NULL;
	print_2Dstr_arr(shifted_arr, size);

	for (i = 0; i < size_i; i++)
		bucket[shifted_arr[i][max_num_len - 1] - '0']++;
	_print_array(bucket, 10);

	/* accumulating bucket array  */
	for (i = 1; i < 10; i++)
		{
			bucket[i] = bucket[i] + bucket[i - 1];
		}
	printf("array after accumulation\n");
	_print_array(bucket, 10);
	/* SORTING */
	for (i = 0, pass = 1; i < max_num_len; i++, pass++, LSDIdx--)
	{
		printf("      __Pass__= %d  LSDIdx: %d   \n", pass, LSDIdx);
		for (j =  size_i ; j  >= 0; j--)
		{
			char *SAIdx = shifted_arr[j];
			printf("J[%d]\n", j);
			LSD = SAIdx[LSDIdx] - '0';
			LSDVal = bucket[LSD];

			if (bucket[LSD])
				bucket[LSD]--;
			printf("shifted_arr[value] = %s\n", shifted_arr[LSDVal]);

		}

	}
	for (i = 0; i < size_i; i++)
		array[i] = output_arr[i];

	/* free out put array*/
	for (i = 0; i < size_i ; i++)
		if (shifted_arr[i])
			free(shifted_arr[i]);
	free(shifted_arr);
	free(bucket);
	free(output_arr);
}
/**

	for (i = 0; i < max_num_len; i++)
	{
		for (i = 0; i < size_i; i++)
		{
			LSD = shifted_arr[i][max_num_len - 1] - '0';


		}

	}
 */
