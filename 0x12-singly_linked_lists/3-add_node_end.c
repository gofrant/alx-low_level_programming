#include"lists.h"
/**
 * add_node_end - addes new node
 * @head: head of list
 * @str: node to be add
 * Return: on success the list if failed Null
 */
list_t *add_node_end(list_t **head, const char *str)
{
	char *dup;
	int len;
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	dup = strdup(str);
	if (dup == NULL)
	{
		free(new);
		return (NULL);
	}
	for (len = 0; str[len]; len++)
		new->str = dup;
	new->len = len;
	new->next = *head

		if (*head == NULL)
			*head = new;

		else
		{
			last = *head;
			while (last->next != NULL)
				last = last->next;
			last->next = new;
		}
	return (*head);
}
