#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *			Using the cocktail shaker sort.
 * @list: The head pointer of the doubly linked list
 *
 * Return: void
 **/

void cocktail_sort_list(listint_t **list)
{
	bool swapped;
	listint_t *current, *end;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = *list;
	swapped = true;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (swapped)
	{
		swapped = false;
		for (; current != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_before(list, &end, &current);
				print_list((const listint_t *)*list);
				swapped = true;
			}
		}

		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_after(list, &end, &current);
				print_list((const listint_t *)*list);
				swapped = true;
			}
		}
	}
}


/**
 * swap_node_before - Swap the nodes
 * @list: The head pointer to the doubly linked list
 * @tail: The node to be swapped
 * @current: The node to be swapped
 **/

void swap_node_before(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;

	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}


/**
 * swap_node_after - Swap the nodes
 * @list: The head pointer to the doubly linked list
 * @tail: The node to be swapped
 * @current: The node to be swapped
 **/

void swap_node_after(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}
