#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		temp = current->prev;

		while (temp && temp->n > current->n)
		{
			temp->next = current->next;
			if (current->next)
				current->next->prev = temp;

			current->prev = temp->prev;
			current->next = temp;

			if (temp->prev)
				temp->prev->next = current;
			else
				*list = current; 

			temp->prev = current;

			print_list(*list);

			temp = current->prev;
		}
		current = next;
	}
}
