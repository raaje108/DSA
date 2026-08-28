#include <stdlib.h>
#include <string.h>

#define MAXV 40
#define MAXE 100

typedef struct Edge {
    int to;
    double value;
    struct Edge* next;
} Edge;

Edge* graph[MAXV];
char* names[MAXV];
int variableCount = 0;


/* Find variable ID */
int getId(char* name)
{
    for (int i = 0; i < variableCount; i++)
    {
        if (strcmp(names[i], name) == 0)
            return i;
    }

    names[variableCount] = name;

    return variableCount++;
}


/* Add graph edge */
void addEdge(int from, int to, double value)
{
    Edge* newEdge = malloc(sizeof(Edge));

    newEdge->to = to;
    newEdge->value = value;
    newEdge->next = graph[from];

    graph[from] = newEdge;
}


/*
 * DFS
 *
 * current = current variable
 * target  = variable we want
 * product = product accumulated so far
 */
double dfs(
    int current,
    int target,
    double product,
    int* visited
)
{
    if (current == target)
        return product;

    visited[current] = 1;

    Edge* edge = graph[current];

    while (edge != NULL)
    {
        if (!visited[edge->to])
        {
            double result = dfs(
                edge->to,
                target,
                product * edge->value,
                visited
            );

            if (result != -1.0)
                return result;
        }

        edge = edge->next;
    }

    return -1.0;
}


double* calcEquation(
    char*** equations,
    int equationsSize,
    int* equationsColSize,
    double* values,
    int valuesSize,
    char*** queries,
    int queriesSize,
    int* queriesColSize,
    int* returnSize
)
{
    /*
     * Reset graph
     */
    variableCount = 0;

    for (int i = 0; i < MAXV; i++)
        graph[i] = NULL;

    /*
     * Build graph
     */
    for (int i = 0; i < equationsSize; i++)
    {
        char* a = equations[i][0];
        char* b = equations[i][1];

        int idA = getId(a);
        int idB = getId(b);

        /*
         * a / b = value
         */
        addEdge(idA, idB, values[i]);

        /*
         * b / a = 1 / value
         */
        addEdge(idB, idA, 1.0 / values[i]);
    }

    /*
     * Answers
     */
    double* answer =
        malloc(queriesSize * sizeof(double));

    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++)
    {
        char* a = queries[i][0];
        char* b = queries[i][1];

        int idA = -1;
        int idB = -1;

        /*
         * Find IDs
         */
        for (int j = 0; j < variableCount; j++)
        {
            if (strcmp(names[j], a) == 0)
                idA = j;

            if (strcmp(names[j], b) == 0)
                idB = j;
        }

        /*
         * Unknown variable
         */
        if (idA == -1 || idB == -1)
        {
            answer[i] = -1.0;
            continue;
        }

        /*
         * a / a = 1
         */
        if (idA == idB)
        {
            answer[i] = 1.0;
            continue;
        }

        int visited[MAXV] = {0};

        answer[i] = dfs(
            idA,
            idB,
            1.0,
            visited
        );
    }

    return answer;
}