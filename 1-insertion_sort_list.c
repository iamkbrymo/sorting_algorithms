#include "sort.h"

/**
 * insertion_sort_list - A function that sort a doubly linked list by insertion
 * @list: The list to sort
 * Return: The list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *head, *prev, *prev_inner, *cur_inner;

	if (list == NULL)
		return;
	if ((*list) == NULL || (*list)->next == NULL)
		return;
	prev = *list;
	cur = (*list)->next;
	head = *list;
	while (cur)
	{
		cur_inner = cur;
		prev_inner = prev;
		while (prev_inner && prev_inner->n > cur_inner->n)
		{
			if (prev_inner->prev == NULL)
				head = cur_inner;
			if (cur_inner == cur)
				cur = prev_inner;
			if (cur_inner->next != NULL)
				cur_inner->next->prev = prev_inner;
			if (prev_inner->prev != NULL)
				prev_inner->prev->next = cur_inner;
			cur_inner->prev = prev_inner->prev;
			prev_inner->next = cur_inner->next;
			cur_inner->next = prev_inner;
			prev_inner->prev = cur_inner;
			prev_inner = cur_inner->prev;
			print_list(head);
		}
		prev = cur;
		cur = cur->next;
	}
	*list = head;
}
