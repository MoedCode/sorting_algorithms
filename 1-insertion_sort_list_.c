#include "sort.h"

/**
 * Swp_dub_list - swap to given node in  in double linked list
 * @node1: pointer to first node.
 * @node2: pointer to second node.
 * @HEAD: a pointer to pointer  to head node of double linked list.
 * Return: (0) if swap done correctly (-1) if one of argument is NULL
 */
int Swp_dub_list(listint_t *node1, listint_t *node2, listint_t **HEAD)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	if (!HEAD || !*HEAD || !node1 || !node2)
		return (-1);
	tmp1 = node1->prev;
	tmp2 = node2->next;

	if (tmp1)
		tmp1->next = node2;
	if (tmp2)
		tmp2->prev = node1;
	node1->next = tmp2;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = tmp1;
	if (tmp1 == NULL)
		*HEAD = node2;
	return (0);
}
/**
 * insertion_sort_list - sort double linked list that have one member integer.
 * @list: aa pointer to pointer  to head node of double linked list.
 *
 * Return: void
 */
void insertion_sort_list_(listint_t **list)
{
	int node_n;
	listint_t *HEAD = *list, *prv_node, *cur_node;



	if (!list || !HEAD || !HEAD->next)
		return;


	cur_node = HEAD;
	while (cur_node)
	{
		prv_node = cur_node->prev;
		node_n = cur_node->n;

		while (prv_node && prv_node->n > node_n)
		{
			Swp_dub_list(prv_node, cur_node, list);
			print_list(*list);
			prv_node = cur_node->prev;
		}
		cur_node = cur_node->next;
	}
}
