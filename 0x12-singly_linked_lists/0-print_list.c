#include"lists.h"
#include<stdio.h>

/**
 * print_list - prints all elements of list
 * @h: the list counter
 * Return: the number of elements in list
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		nodes++;
			h = h->next;
	}

	return (nodes);

}
