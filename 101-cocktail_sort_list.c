#include "header.h"

/**
 * cocktail_sort_list - implements cocktail sort algorithm
 * @head: sorted/unsorted list
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **head)
{
	int swapped;
	listint_t *start = *head, *end = NULL, *current = NULL;

	if (head == NULL)
		return;
	do {
		swapped = 0;
		current = start;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(head, current, current->next);
				print_list(*head);
				swapped = 1;
			}
			else
				current = current->next;
			if (current->next == NULL)
				break;
		}
		if (swapped == 0)
			break;
		end = current;
		current = current->prev;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(head, current->prev, current);
				print_list(*head);
				swapped = 1;
			}
			else
				current = current->prev;
			if (current->prev == NULL)
				break;
		}
		start = current->next;
	} while (swapped);
}

/**
 * swap_nodes - swaps two neighbouring nodes
 * @head: pointer to list
 * @node1: first node
 * @node2: second node
 *
 * Return: nothing
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *mylinks[4] = {0};

	if (head == NULL || node1 == NULL || node2 == NULL)
		return;
	if (node1 == node2)
		return;
	mylinks[0] = node1->prev;
	mylinks[1] = node1->next;
	mylinks[2] = node2->prev;
	mylinks[3] = node2->next;
	if (node1->next == node2)
	{
		node1->prev = mylinks[1];
		node1->next = mylinks[3];
		node2->prev = mylinks[0];
		node2->next = mylinks[2];
	}
	else
	{
		node2->prev = mylinks[3];
		node2->next = mylinks[1];
		node1->prev = mylinks[2];
		node1->next = mylinks[0];
	}
	outer_links(node1, head);
	outer_links(node2, head);
}

/**
 * outer_links - sets the outer links of nodes
 * @node: node
 * @head: pointer to list
 *
 * Return: nothing
 */
void outer_links(listint_t *node, listint_t **head)
{
	if (node->prev != NULL)
		node->prev->next = node;
	else
		*head = node;
	if (node->next != NULL)
		node->next->prev = node;
}
