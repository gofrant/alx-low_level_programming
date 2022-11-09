#include <unistd.h>
/**
 * _putchar - write char to input
 * @c: char to be return
 * Return: on success 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
