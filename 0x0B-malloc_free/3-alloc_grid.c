#include "main.h"
/**
 * alloc_grid - allocates a grid
 * @width: take in width
 * @hight: hight of grid
 * Return: grid with freed space
 */

int **alloc_grid(int width, int hight)
{
	int **grid;
	int i, j;

	if (width <= 0 || hight <= 0)
	{
		return (NULL);
	}
	grid = malloc(sizeof(int *) * hight);
	if (grid == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < hight; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			for (i = i - 1; i >= 0; i--)
			{
				free(grid[i]);
			}
			free(grid);
			return (NULL);
		}
	}
	for (i = 0; j < width; j++)
		grid[i][j] = 0;
	return (grid);
}
