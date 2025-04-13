#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the list head
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node2->next = node1;
	node1->prev = node2;

	print_list(*list);
}

/**
 * cocktail_forward - Performs forward pass of cocktail sort
 * @list: Pointer to the head of the list
 * @start: Starting node of the forward pass
 *
 * Return: 1 if a swap occurred, 0 otherwise
 */
int cocktail_forward(listint_t **list, listint_t **start)
{
	int swapped = 0;

	while ((*start)->next)
	{
		if ((*start)->n > (*start)->next->n)
		{
			swap_nodes(list, *start, (*start)->next);
			swapped = 1;
		}
		else
			*start = (*start)->next;
	}

	return (swapped);
}

/**
 * cocktail_backward - Performs backward pass of cocktail sort
 * @list: Pointer to the head of the list
 * @end: Starting node of the backward pass
 *
 * Return: 1 if a swap occurred, 0 otherwise
 */
int cocktail_backward(listint_t **list, listint_t **end)
{
	int swapped = 0;

	while ((*end)->prev)
	{
		if ((*end)->n < (*end)->prev->n)
		{
			swap_nodes(list, (*end)->prev, *end);
			swapped = 1;
		}
		else
			*end = (*end)->prev;
	}

	return (swapped);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start;
	int swapped_f, swapped_b;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	do {
		swapped_f = cocktail_forward(list, &start);
		if (!swapped_f)
			break;

		start = start->prev;
		swapped_b = cocktail_backward(list, &start);
	} while (swapped_b);
}

