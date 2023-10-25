#include "sort.h"
/**
 * swap - function that swaps 2 elements of the array
 * @x: first element to be swapped
 * @y: second  element to be swapped
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
 * partition - sorts the array portion according to start_idx and end
 *
 * @array: pointer to array
 * @size: size of the array
 * @start_idx: index to start_idx from
 * @end_idx: index to end with
 * Return: index of the pivot, 0 on error
 */
size_t Part_Hor_sort(int *array, size_t size, size_t end_idx, size_t start_idx)
{
	int pivot;
	size_t i, j;

	pivot = array[start_idx];
	i = end_idx - 1;
	j = start_idx + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);

		swap(&array[i], &array[j]);
		print_array(array, size);

	}

}

/**
 * qs - recursive function that sorts the array using
 * quicksort algorithm
 * @array: pointer to the array of integers to sort
 * @size: size of the array
 * @start_idx: index to start_idx array partition to order
 * @end_idx: index to end array partition to order
 * Return: 1 on error if array is NULL or start_idx <= end, 0 otherwise
 */
void quic_sort_rec(int *array,  size_t size, size_t start_idx, size_t end_idx)
{

	if (start_idx < end_idx)
	{
	size_t pivot = Part_Hor_sort(array, size, start_idx, end_idx);

		quic_sort_rec(array, size, start_idx, pivot - 1);
		quic_sort_rec(array, size, pivot, end_idx);
	}
}

/**
 * quick_sort - sorting array using recursive str_end_sort function
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quic_sort_rec(array, size, 0, size - 1);
}
