#include "sort.h"

/**
 * insertion_sort_list - in ascending order using the Insertion sort algorithm
 * @list: the doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swaped;
	size_t flag = 1;

	if (list == NULL || *list == NULL)
		return;
	swaped = *list;
	while (flag)
	{	flag = 0;
		current = *list;
		while (current->next)
		{
			if (current->n > current->next->n)
			{	swaped = current->next;
				if (!swaped->next)
					swaped->prev->next = NULL;
				else
				{	swaped->prev->next = swaped->next;
					swaped->next->prev = swaped->prev;
				}
				if (!current->prev)
				{
					swaped->next = *list;
					(*list)->prev = swaped;
					*list = swaped;
					swaped->prev = NULL;
				}
				else
				{
					current->prev->next = swaped;
					swaped->prev = current->prev;
					swaped->next = current;
					current->prev = swaped;
				}
				print_list(*list);
				flag = 1;
				break;
			}
			current = current->next;
		}
	}
}
