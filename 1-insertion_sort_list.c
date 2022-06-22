#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @x: address of the first node
 * @y: address of the second node
 * Return: void
 */

void swap_nodes(listint_t *x, listint_t *y)
{
	if (x->prev)
	{
		x->prev->next = y;
	}
	if (y->next)
	{
		y->next->prev = x;
	}
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: doubly linked list to be ordered
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	i = *list;
	while (i)
	{
		j = i;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_nodes(j->prev, j);
				if (!j->prev)
				{
					*list = j;
				}
				print_list((const listint_t *)*list);
			}
			else
			{
				j = j->prev;
			}
		}
		i = i->next;
	}
}
