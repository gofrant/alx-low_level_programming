#include<stdlib.h>
#include<function_pointers.h>

/**
 * array_intrator - execute a function
 * @array: array to iterat
 * @size: size of array
 * @action: pointer to function used
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (!array || !action)
		return;

	for (i - 0; i < size; i++)
		action(array[i]);
}
