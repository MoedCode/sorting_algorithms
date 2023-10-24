#include <stdio.h>
#include <stdlib.h>

typedef struct listint_t
{
    int n;
    struct listint_t *next;
} listint_t;

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *ptr, *node_end;

    node_end = malloc(sizeof(listint_t));
    if (node_end == NULL)
        return NULL;

    node_end->n = n;
    node_end->next = NULL;

    if (*head == NULL)
    {
        *head = node_end;
        return node_end;
    }
    /*  missing to initialized  ptr variable  to *head before the while loop*/
    ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = node_end;

    return node_end;
}

int main(void)
{
    listint_t *head = NULL, *ptr;
    for (int i = 0; i < 5; i++)
    {
        add_nodeint_end(&head, i);
    }
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d\n", ptr->n);
    }
    return 0;
}