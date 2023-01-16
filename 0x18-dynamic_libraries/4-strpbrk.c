#include "main.h"
#include <string.h>
/**
 * _strpbrk - searches a string for any set of byte
 * @s: the string to search
 * @accept: search string
 * Return: a pointer to the byte in s that matches one of the bytes
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j, len, len2;
	char *c;

	len = strlen(s);
	len2 = strlen(accept);

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (s[i] == accept[j])
			{
				c = &s[i];
				return (c);
			}
		}
	}
	return (NULL);
}
