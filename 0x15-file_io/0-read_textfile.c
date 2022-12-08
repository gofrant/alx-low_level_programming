#include <stdlib.h>
#include"main.h"
#include <fcntl.h>
/**
 * read_textfile - read a file and print the number of char in it
 * @filename: Apointer to file
 * @letters: number of letters
 * Return: if the function failed 0,onsuccess number of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}
