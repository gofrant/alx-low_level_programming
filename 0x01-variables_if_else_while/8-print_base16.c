#include <stdio.h>
/**
 * main -prints the number
 * Return: Always 0
 */
int main(void)
{
	int num;
	char l;

	for (num = 0; num < 10 ; num++)

		putchar((num % 10) + '0');

	for (l = 'a'; l <= 'f'; l++)
		putchar(l);

	putchar('\n');

	return (0);
}


