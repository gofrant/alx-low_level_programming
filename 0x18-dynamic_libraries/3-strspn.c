#include "main.h"
#include <string.h>
/**
 * _strspn - gets the length of a prefix substring
 * @s: the string
 * @accept: the substring
 * Return: number of bytes in initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int v = strspn(s, accept);

	return (v);
}
