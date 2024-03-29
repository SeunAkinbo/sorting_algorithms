#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


/*Function Prototypes*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
size_t partition(int *array, int lb, int ub, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node_after(listint_t **list, listint_t **tail, listint_t **current);
void swap_node_before(listint_t **list, listint_t **tail, listint_t **current);
void counting_sort(int *array, size_t size);
int max_num(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size);
void merge_sort_recursive(int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap_heap(int *a, int *b);
void heapify(int *array, size_t size, size_t base, size_t root);
void radix_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /*SORT_H*/
