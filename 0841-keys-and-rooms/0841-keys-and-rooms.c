#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = calloc(roomsSize, sizeof(bool));

    int* stack = malloc(roomsSize * sizeof(int));
    int top = 0;

    // Start from room 0
    stack[top++] = 0;
    visited[0] = true;

    int count = 1;

    while (top > 0) {
        int room = stack[--top];

        for (int i = 0; i < roomsColSize[room]; i++) {
            int key = rooms[room][i];

            if (!visited[key]) {
                visited[key] = true;
                count++;
                stack[top++] = key;
            }
        }
    }

    free(visited);
    free(stack);

    return count == roomsSize;
}