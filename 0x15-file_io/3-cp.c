#include "main.h"
#include<stdio.h>
#include<stdlib.h>
char *create_buffer(char *file);
void close_file(int fd);
/**
 * create_buffer - alloc bytes for buffer
 * @file: the name of the file stored
 * Return: Apointer to newly allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILEND, "ERROR: can't write to %s \n, file");
		exit(00);
	}
	return (buffer);
}
/**
 * close_file - closes file
 * @fd: the file descriptor to be closed;
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILEND, "ERROR: can't close fd %d\n"' fd);
		exit(100);
	}
/**
* main - main function
* @argc: argument
* @argv: function
* Return: on success 1
*/
int main(int argc, char *argv[])
{

	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILEND, "Usage: cp file_from file_to\n");
		exit(98);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O-RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r ==-1)
		{
			dprintf(STDERR_FILEND, "Error : can't read from file % s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILEND, "Error : can't write to file % s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
