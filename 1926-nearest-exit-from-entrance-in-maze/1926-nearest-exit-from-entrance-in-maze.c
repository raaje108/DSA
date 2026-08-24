#include <stdlib.h>

int nearestExit(char** maze, int mazeSize, int* mazeColSize,
                 int* entrance, int entranceSize) {

    int m = mazeSize;
    int n = mazeColSize[0];

    int total = m * n;

    // Queue
    int* queue = malloc(total * sizeof(int));

    int front = 0;
    int rear = 0;

    // Encode (row, col) as row * n + col
    queue[rear++] = entrance[0] * n + entrance[1];

    // Mark entrance visited
    maze[entrance[0]][entrance[1]] = '+';

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int steps = 0;

    while (front < rear) {

        int size = rear - front;
        steps++;

        for (int k = 0; k < size; k++) {

            int pos = queue[front++];

            int r = pos / n;
            int c = pos % n;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside maze
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Wall or visited
                if (maze[nr][nc] != '.')
                    continue;

                // Boundary = exit
                if (nr == 0 || nr == m - 1 ||
                    nc == 0 || nc == n - 1) {

                    free(queue);
                    return steps;
                }

                // Mark visited
                maze[nr][nc] = '+';

                queue[rear++] = nr * n + nc;
            }
        }
    }

    free(queue);

    return -1;
}