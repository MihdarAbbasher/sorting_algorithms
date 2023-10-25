#include "sort.h"

/**
 * insertion_sort_list - sort by insertion
 * @list: list to be sorted
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *c_node;
	
	c_node = *list;
	if (c_node == NULL || c_node->next == NULL)
		return;
	c_node = c_node->next;
	while (c_node)
	{
		tmp = c_node->prev;
		if (tmp->n > c_node->n)
		{
			tmp->next = c_node->next;
			if (c_node->next)
				(c_node->next)->prev = tmp;
			while (tmp && tmp->n > c_node->n)
			{
				tmp = tmp->prev;
			}
			c_node->prev = tmp;
			if (tmp)
			{
				c_node->next = tmp->next;
				(tmp->next)->prev = c_node;
				tmp->next = c_node;
			}
			else
			{
				c_node->next = *list;
				(*list)->prev = c_node;
				*list = c_node;
			}
			print_list(*list);
		}
		c_node = c_node->next;
	}
}

