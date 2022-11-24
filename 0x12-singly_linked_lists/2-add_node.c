#include"lists.h"
#include<strings.h>
/**
 * add_node - addes new node
 * @head: head of list
 * @str: node to be adde
 * Return: on success the list if failed Null
 */
list_t *add_node(list_t **head, const char *str)
{
	char *dup;
	int len;
	list_t *new;
	size_t nchar;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	dup = strdup(str);
	if (dup == NULL)
	{
		free(new);
		return (NULL);

	for (len = 0; str[len]; len++)
		new->str = dup;
	new->len = len;
	new->next = *head
	return (*head);
}
