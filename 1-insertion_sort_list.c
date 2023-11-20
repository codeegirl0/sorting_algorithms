#include "sort.h"

/**
 * swapping - to swap elements in the list
 * @head: list head
 * @a: a node
 * @b: a node
 */
void swapping(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *ax1 = NULL, *ax2 = NULL;

	if (a == NULL || b == NULL)
		return;
	ax1 = a->prev;
	ax2 = b->next;
	if (ax1)
		ax1->next = b;
	if (ax2)
		ax2->prev = a;
	a->next = ax2;
	a->prev = b;
	b->next = a;
	b->prev = ax1;
	if (ax1 == NULL)
		*head = b;
}
/**
 * insertion_sort_list  - insert sort list
 * @list: the doubly liked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int val;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;
	while (head)
	{
		prev = head->prev;
				val = head->n;

		while (prev && prev->n > val)
		{
			swapping(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
