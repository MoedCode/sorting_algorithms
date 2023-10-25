#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#define DEBUG(M) printf("%s%s:%d\n", M, __FILE__, __LINE__)
#define DBG printf("%s:%d\n", __FILE__, __LINE__)
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

int printIntAr(int arr[], size_t size);
void swap2(int *x, int *y);

void bubble_sort(int *array, size_t size);
void insertion_sort_list_(listint_t **list);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void selection_sort_1(int *array, size_t size);

void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void shell_sort(int *array, size_t size);

void counting_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);
void print_reverse(listint_t *lst);
listint_t *get_tail(listint_t *lst);
#endif
