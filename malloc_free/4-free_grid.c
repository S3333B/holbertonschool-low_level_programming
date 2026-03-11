#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created by alloc_grid
 * @grid: grid to free
 * @height: number of rows in the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}

	free(grid);
}
