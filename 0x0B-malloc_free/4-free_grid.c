#include "main.h"
/**
 * free_grid - alloc a grid, make space free space
 * @grid: wedth of grid
 * @height: hight of grid
 * Return: free grid
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
