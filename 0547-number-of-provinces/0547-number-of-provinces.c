#include <stdlib.h>

void dfs(int city, int** isConnected, int n, int* visited)
{
    visited[city] = 1;

    for (int next = 0; next < n; next++)
    {
        if (isConnected[city][next] == 1 &&
            visited[next] == 0)
        {
            dfs(next, isConnected, n, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize,
                  int* isConnectedColSize)
{
    int n = isConnectedSize;

    int* visited = calloc(n, sizeof(int));

    int provinces = 0;

    for (int city = 0; city < n; city++)
    {
        if (visited[city] == 0)
        {
            provinces++;

            dfs(city, isConnected, n, visited);
        }
    }

    free(visited);

    return provinces;
}