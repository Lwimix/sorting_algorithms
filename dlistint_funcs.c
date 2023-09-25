#include "sort.h"

/**
 * dlistint_len - Returns the number of elements in a linked `listint_t`
 * list.
 *
 * @h: Pointer to a Constant `listint_t` list, which represents the header
 * node of the doubly linked list.
 *
 * Return: Number of nodes
 */

size_t dlistint_len(const listint_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * get_dnodeint_at_index - Returns the nth node of a `listint_t` linked list.
 *
 * @head: Pointer to a `listint_t` list type, represents the head of the
 * doubly linked list.
 * @index: Unsigned Integer value, index of the node to be returned.
 *
 * Return: Address of the nth node (Success)
 *	   NULL (Failure).
 */
listint_t *get_dnodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *curr = head;

	while (count != index && curr != NULL)
	{
		curr = curr->next;
		count++;
	}

	if (count != index)
		return (NULL);

	return (curr);
}
