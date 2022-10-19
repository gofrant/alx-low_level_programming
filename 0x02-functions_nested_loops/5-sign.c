#include "main.h"

/**
 *print_sign - prints the sign of number
 * @n: print the number of the sign
 * Return:  1 if number positive
 * 0 if number is zero
 * -1 if the number smaller than zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		putchar('0');
		return (0);
	}
	else
	{
		putchar('-');
		return (-1);
	}
}
