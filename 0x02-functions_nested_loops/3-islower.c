#include "main.h"

/**
 * _islower -checkes if the char is lower case
 * @c : the charactur
 * Return: 1 if lower case 0 if not
 */
int _islower(int c)
{

	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
