#include <stdlib.h>

typedef struct Node {
    int city;
    int cost;
    struct Node* next;
} Node;

/* Add an edge to adjacency list */
void addEdge(Node** graph, int from, int to, int cost)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->city = to;
    newNode->cost = cost;
    newNode->next = graph[from];

    graph[from] = newNode;
}

/* DFS */
void dfs(int city, Node** graph, int* visited, int* answer)
{
    visited[city] = 1;

    Node* current = graph[city];

    while (current != NULL)
    {
        int nextCity = current->city;

        if (!visited[nextCity])
        {
            /*
             * cost = 1 means the original road
             * points AWAY from city 0.
             */
            *answer += current->cost;

            dfs(nextCity, graph, visited, answer);
        }

        current = current->next;
    }
}

int minReorder(int n, int** connections, int connectionsSize,
               int* connectionsColSize)
{
    Node** graph = calloc(n, sizeof(Node*));

    /*
     * For original road:
     *
     * a -> b
     *
     * Store:
     * a -> b : cost 1
     * b -> a : cost 0
     */
    for (int i = 0; i < connectionsSize; i++)
    {
        int a = connections[i][0];
        int b = connections[i][1];

        addEdge(graph, a, b, 1);
        addEdge(graph, b, a, 0);
    }

    int* visited = calloc(n, sizeof(int));

    int answer = 0;

    dfs(0, graph, visited, &answer);

    /*
     * Free memory
     */
    for (int i = 0; i < n; i++)
    {
        Node* current = graph[i];

        while (current != NULL)
        {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(graph);
    free(visited);

    return answer;
}