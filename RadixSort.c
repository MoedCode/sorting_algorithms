#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int getMaxInAr(int *array, size_t size);
 int number_len(int n);
char *int_to_string(int n, int max_len);
size_t freeDoubleArray(char **argv);



void radix_sort(int *array, size_t size)
{
	int max_num, max_num_len , size_i = (int)size, i ,j, k, L, x, y,u,
	*bucket = calloc(sizeof(int), 10), LSD, LSDVal, pass, LSDIdx,
	*output_arr = calloc(sizeof(int), size_i);
	char **shifted_arr;


	max_num = getMaxInAr(array, size);
	max_num_len = number_len(max_num);
	LSDIdx = max_num_len - 1;




	/* SORTING */
	for (i = 0, pass = 1; i < max_num_len; i++, pass++, LSDIdx--)
	{
				/* assign output array index's*/
		shifted_arr = malloc((size_i) * sizeof(char *));
		if (!shifted_arr)
			return;
		for (L = 0; L < size_i; L++)
			shifted_arr[L] = strdup(int_to_string(array[L],  max_num_len));
		shifted_arr[L] = NULL;

		for (x = 0; x < size_i; x++)
			bucket[shifted_arr[x][max_num_len - 1] - '0']++;

		/* accumulating bucket array  */
		for (y = 1; y < 10; y++)
			{
				bucket[y] = bucket[y] + bucket[y - 1];
			}
			/* ____________________________________________________*/
			/* ____________________________________________________*/
		printf("      __Pass__= %d  LSDIdx: %d   \n", pass, LSDIdx);
		for (j =  size_i - 1, k = 0; j  >= 0; j--, k++)
		{
			char *SAIdx = shifted_arr[j];
			LSD = SAIdx[LSDIdx] - '0';
			LSDVal = bucket[LSD] ;
			if (LSDVal)
				LSDVal --;
			if (bucket[LSD])
				bucket[LSD]--;
printf("k[%d]j[%d]LSDval[%d] atio[%d] ",k ,j,LSDVal,  atoi(shifted_arr[LSDVal]));
		printf("array[k]=%d \n",array[k]);
		if(shifted_arr[LSDVal] && output_arr[k])
			output_arr[k] =  atoi(shifted_arr[LSDVal]);

		}
			puts("Targeted  Array ");
			_print_array(array, size);
			puts("shifted  Array ");
			print_2Dstr_arr(shifted_arr, size);
		for (u = 0; u < size_i; u++)
			array[u] = output_arr[u];
		freeDoubleArray(shifted_arr);

	}


	/* free out put array*/

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

		j == size_i -1? putchar('{'): 1 == 1;
		j > size_i -1? printf(", "): 1 == 1;
		printf("=> %s", shifted_arr[LSDVal]);
		j == 0?   putchar(10): 1 == 1;
 */


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
 * int_to_string - shift and cast  given int to string  right  by adding 0
 * to he left number of zeros = max_len - length of the number
 * it uses  number_len function to calculate it
 * returns the string
 * @n:number to be shift
 * @max_len: number of shifting steps must >= number length
 * Return: (char*) string for a casted and shifted number,
 * (NULL) in cases error
 */
char *int_to_string(int n, int max_len)
{
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
size_t freeDoubleArray(char **argv)
{
	size_t i, j;

	for (j = 0; argv[j]; j++)
			;
	for (i = 0; i <= j; i++)
		if(argv[i])
		{

			free(argv[i]);
			argv[i] = NULL;
 		}
	if(argv)
	{
	free(argv);
	argv = NULL;
	}
	return (i);
}