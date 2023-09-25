#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void lumoto(int *array, int low, int high, size_t size);
size_t dlistint_len(const listint_t *h);
listint_t *get_dnodeint_at_index(listint_t *head, unsigned int index);
void free_dlistint(listint_t *head);
void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
#endif
