#include "sort.h"
#include "stdlib.h"
void print_reverse(listint_t *lst);
listint_t *get_tail(listint_t *lst);
int swap_last_two_nodes(listint_t *curr);
int swap_curr_with_prev_node(listint_t *curr);
int swap_first_two_nodes(listint_t *curr, listint_t **list);

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 *  integers in ascending order using the Insertion sort algorithm
 *
 * @param
 * @list: address of the pointer to the head of  double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	curr = *list;

	while (curr != NULL)
	{
		listint_t *curr_cpy = curr;

		while ((curr_cpy)->prev != NULL && (curr_cpy)->n < (curr_cpy)->prev->n)
		{
			if (curr->next == NULL)
				swap_last_two_nodes(curr_cpy);
			else if (curr->prev->prev == NULL)
				swap_first_two_nodes(curr_cpy, list);
			else if (curr->prev->prev != NULL)
				swap_curr_with_prev_node(curr_cpy);
			print_list(*list);
		}
		(curr) = (curr)->next;
	}
}

/**
 * swap_last_two_nodes - function that swaps the last 2 nodes in
 * double linked list
 *
 * @param
 * @curr: pointer to the last node to be swapped with
 * the one before it
 *
 * Return: 1 on success or -1 on failure
 */
int swap_last_two_nodes(listint_t *curr)
{
	listint_t *prev_prev;
	listint_t *prev;

	if (curr->next != NULL)
	{
		return (-1);
	}

	prev_prev = curr->prev->prev;
	prev = curr->prev;

	curr->prev = prev_prev;
	curr->next = prev;

	prev->next = NULL;
	prev->prev = curr;
	prev_prev->next = curr;
	return (1);
}
/**
 * swap_first_two_nodes - function that swaps the first 2 nodes in
 * double linked list
 *
 * @param
 * @curr: pointer to the second node to be swapped with
 * the first node.
 *
 * @list: address of the pointer to the head of  double linked list
 *
 * Return: 1 on success or -1 on failure
 */
int swap_first_two_nodes(listint_t *curr, listint_t **list)
{
	listint_t *prev;
	listint_t *curr_next;

	if (curr->prev->prev != NULL || curr->prev == NULL || curr == NULL)
		return (-1);

	prev = ((curr)->prev);
	curr_next = curr->next;

	curr->next = prev;
	curr->prev = NULL;

	prev->next = curr_next;
	prev->prev = curr;
	curr_next->prev = prev;

	(*list) = curr;

	return (1);
}
/**
 * swap_curr_with_prev_node - function that swaps a node with
 * the one before it
 * @param
 * @curr: pointer to the node to be swapped with the one
 * before it
 *
 * Return: 1 on success or -1 on failure
 */
int swap_curr_with_prev_node(listint_t *curr)
{
	listint_t *prev;
	listint_t *curr_next;

	if (curr->prev->prev == NULL || curr->prev == NULL || curr == NULL)
		return (-1);

	if (curr == NULL)
		return (-1);

	prev = ((curr)->prev);
	curr_next = curr->next;

	(curr)->next = prev;
	prev->prev->next = curr;
	(curr)->prev = prev->prev;

	(prev)->next = curr_next;
	curr_next->prev = prev;
	(prev)->prev = curr;
	return (1);
}

/**
 * get_tail - function that gets the tail of the double linked list
 *
 * @param
 * @lst: address of the pointer to the head of  double linked list
 *
 * Return: a pointer to the linked list
 */
listint_t *get_tail(listint_t *lst)
{
	listint_t *tail;
	listint_t *curr = lst;

	while (curr)
	{
		if (curr->next == NULL)
		{
			tail = curr;
		}
		curr = curr->next;
	}
	return (tail);
}

/**
 * print_reverse - function that print linked list in
 * reverse order.
 *
 * @param
 * @lst: address of the pointer to the head of  double linked list.
 */
void print_reverse(listint_t *lst)
{
	listint_t *curr = lst;

	while (curr)
	{
		printf("%i, ", curr->n);
		curr = curr->prev;
	}
}
