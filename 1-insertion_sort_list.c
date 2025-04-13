#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current->next;
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			/* Swap current and insert */
			if (insert->prev)
				insert->prev->next = current;
			current->prev = insert->prev;

			insert->next = current->next;
			if (current->next)
				current->next->prev = insert;

			current->next = insert;
			insert->prev = current;

			if (!current->prev)
				*list = current;

			insert = current->prev;

			print_list(*list);
		}
		current = tmp;
	}
}

