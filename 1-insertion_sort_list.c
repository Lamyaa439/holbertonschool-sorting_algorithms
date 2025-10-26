#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * @list:...
 * Return:...
 */
void insertion_sort_list(listint_t **list)
{

	listint_s *sorted = NULL;
	listint_s *curr = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (curr != NULL)
	{
		struct listint_s *next = curr->next;

		if (sorted == NULL || sorted->data >= curr->data)
		{
			curr->next = sorted;
			if (sorted != NULL)
				sorted->prev = curr;
			sorted = curr;
			sorted->prev = NULL;
		}
		else
		{
			listint_s *current_sorted = sorted;

			while (current_sorted->next != NULL &&
current_sorted->next->data < curr->data)
			{
				current_sorted = current_sorted->next;
			}
			curr->next = current_sorted->next;
			if (current_sorted->next != NULL)
				current_sorted->next->prev = curr;
			current_sorted->next = curr;
			curr->prev = current_sorted;
		}
		curr = next;
	}
	*list = sorted;
	return;
}
