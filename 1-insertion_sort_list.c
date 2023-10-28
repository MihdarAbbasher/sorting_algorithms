#include "sort.h"

/**
 * insertion_sort_list - sort by insertion
 * @list: list to be sorted
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *c_node, *next;

	c_node = *list;
	if (c_node == NULL)
		return;
	c_node = c_node->next;
	while (c_node)
	{
		prev = c_node->prev;
		next = c_node->next;
		while (prev && prev->n > c_node->n)
		{
			prev->next = c_node->next;
			if (c_node->next)
				c_node->next->prev = prev;
			c_node->next = prev;
			c_node->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = c_node;
			else
				*list = c_node;
			prev->prev = c_node;
			print_list(*list);
			prev = c_node->prev;
		}
		c_node = next;
	}
}

