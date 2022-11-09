#include"main.h"
/**
 * _strln - count arry
 * @s: array element
 * Return: 1
 */
int _strln(char *s)
{
	unsigned int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);

}
/**
 * _strcpy - copy array
 * @src: array of elements
 * @dest: dest array
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - array of pointer
 * @str: array of elements
 * Return: pointer
 */
char *_strdup(char *str)
{
	char *dst;
	unsigned int size;

	if (str == 0)
	{
		return (NULL);
	}
	size = _strln(str) + 1;
	dst =  (char *) malloc(size * sizeof(char));
	if (dst == 0)
	{
		return (NULL);
	}
	_strcpy(dst, str);
	return (dst);
}
