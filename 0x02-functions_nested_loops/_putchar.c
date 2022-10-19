#include<main.h>
#include<unistd.h>

/**
 * _putchar -write char to std
 * @c: rhe character to print
 *
 * Return : on success 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
