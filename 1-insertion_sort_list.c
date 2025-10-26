#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: pointer to pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	struct listint_s *sorted = NULL;
	struct listint_s *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;

	while (curr != NULL)
	{
		struct listint_s *next = curr->next;

		if (sorted == NULL || sorted->n >= curr->n)
		{
			curr->next = sorted;

			if (sorted != NULL)
				sorted->prev = curr;

			sorted = curr;
			sorted->prev = NULL;
			print_list(sorted);
		}
		else
		{
			struct listint_s *current_sorted = sorted;

			while (current_sorted->next != NULL &&
			       current_sorted->next->n < curr->n)
			{
				current_sorted = current_sorted->next;
			}

			curr->next = current_sorted->next;

			if (current_sorted->next != NULL)
				current_sorted->next->prev = curr;

			current_sorted->next = curr;
			curr->prev = current_sorted;
			print_list(sorted);

		}

		curr = next;
	}

	*list = sorted;
}
