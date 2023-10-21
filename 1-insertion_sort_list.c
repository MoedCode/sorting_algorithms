#include "sort.h"
#include "stdlib.h"
void print_reverse(listint_t *lst);
listint_t *get_tail(listint_t *lst);

int swap_last_two_nodes(listint_t *curr)
{
	listint_t *prev_prev;
	listint_t *prev;
	if (curr->next != NULL)
	{
		return -1;
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
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list;

	while (curr != NULL)
	{
		listint_t *curr_cpy = curr;

		while ((curr_cpy)->prev != NULL && (curr_cpy)->n < (curr_cpy)->prev->n)
		{

			/*printf("curr = %i < ", curr_cpy->n);*/
			/*printf("prev = %i\n", curr->prev->n);*/

			if (curr->next == NULL)
				swap_last_two_nodes(curr_cpy);
			else if (curr->prev->prev == NULL)
				swap_first_two_nodes(curr_cpy, list);
			else if (curr->prev->prev != NULL)
				swap_curr_with_prev_node(curr_cpy);
			print_list(*list);

			/**
			 * listint* _t *tail = get_tail(*list);
			 * print_r* everse(tail);
			 * puts(""* );
			 * puts(""* );
			 */
		}
		/*puts("-----");*/
		(curr) = (curr)->next;
	}
}
/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
/**
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}
*/
/**
 * main - Entry point
 *
 * Return: Always 0
 */
/**
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);

	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);

	return (0);
}
*/

/**
 * void insertion_sort_list(listint_t **list);
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		int j = i;

		while (j > 0 && arr[j] < arr[j - 1])
		{
			int tmp = arr[j];

			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;

			j--;
			print_array(arr, size);
		}
	}
}
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
	return tail;
}

void print_reverse(listint_t *lst)
{
	listint_t *curr = lst;

	while (curr)
	{
		printf("%i, ", curr->n);
		curr = curr->prev;
	}
}
