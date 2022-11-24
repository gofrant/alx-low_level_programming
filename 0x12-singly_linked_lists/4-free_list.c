#include"lists.h"
/**
 * free_list - delete node
 * @head: head of list
 * Return: on success the list deleted if failed Null
 */
void free_list(list_t *head)
{
	list_t tmp;

	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}

