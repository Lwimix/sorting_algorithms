#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using Insertion Sort algortihm.
 *
 * @list: Pointer to an array of pointers to listint_t defined datatype
 * which represents the integer values through a doubly linked list data
 * structure.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *to_insert, *to_compare;

	if (list == NULL)
		return;

	to_insert = (*list)->next;
	while (to_insert != NULL)
	{
		to_compare = to_insert->prev;
		while (to_compare != NULL)
		{
			if (to_insert->n < to_compare->n)
			{
				to_insert->prev = to_compare->prev;
				if (to_compare->prev != NULL)
					to_compare->prev->next = to_insert;
				to_compare->next = to_insert->next;
				if (to_insert->next != NULL)
					to_insert->next->prev = to_compare;
				to_insert->next = to_compare;
				to_compare->prev = to_insert;
				if (to_insert->prev == NULL)
					*list = to_insert;

				print_list(*list);
			}
			else if (to_insert->n >= to_compare->n)
				break;

			to_compare = to_insert->prev;
		}
		to_insert = to_insert->next;
	}
}
