#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of a doubly linked list
 *
 * Description: The function sorts the linked list using the
 *              Insertion sort algorithm and prints the list
 *              after each time two elements are swapped.
 *
 * Return: void
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* Already sorted or empty list */

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;
		next_node = current->next;

		while (temp != NULL && temp->n > current->n)
		{
			/* Swap nodes */
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = temp;

			temp->next = current->next;
			current->prev = temp->prev;

			temp->prev = current;
			current->next = temp;

			print_list(*list); /* Prints list after swapping */

			temp = current->prev;
		}
		current = next_node;
	}

}
