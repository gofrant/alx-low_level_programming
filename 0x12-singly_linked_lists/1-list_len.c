#include"lists.h"
/**
 * list_len - length of list
 * @h: counter of length
 * Return: number of elements on list
 */
size_t list_len(const list_t *h)
{
	size_t nodes = 0;

	while (h != NULL)
	{
		h = h->next;
		nodes++;
	}
	return (nodes);
}
