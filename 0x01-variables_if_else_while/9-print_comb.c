#include <stdio.h>
/**
 * main -print all comb of digit
 * Return: Always 0
 */
int main(void)
{
	int n;

	for (n = 48; n < 50; n++)
	{
		putchar(n);
		if (n != 57)
		{
			putchar(',');
			putchar(' ');
		}
		putchar('\n');
		return (0);
	}
}
