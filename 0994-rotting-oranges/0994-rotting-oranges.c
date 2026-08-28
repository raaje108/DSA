#include <stdlib.h>

typedef struct {
    int r;
    int c;
} Point;

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];

    Point* queue = malloc(rows * cols * sizeof(Point));

    int front = 0;
    int rear = 0;
    int fresh = 0;

    // Put all initially rotten oranges in the queue
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == 2)
            {
                queue[rear].r = r;
                queue[rear].c = c;
                rear++;
            }
            else if (grid[r][c] == 1)
            {
                fresh++;
            }
        }
    }

    int minutes = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (front < rear && fresh > 0)
    {
        // Number of oranges at current level
        int size = rear - front;

        for (int i = 0; i < size; i++)
        {
            int r = queue[front].r;
            int c = queue[front].c;

            front++;

            // Check 4 directions
            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols)
                {
                    continue;
                }

                // Fresh orange
                if (grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;

                    fresh--;

                    queue[rear].r = nr;
                    queue[rear].c = nc;

                    rear++;
                }
            }
        }

        minutes++;
    }

    free(queue);

    if (fresh > 0)
        return -1;

    return minutes;
}