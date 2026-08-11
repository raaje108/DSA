#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize,
                       int* returnSize) {

    int *ans = calloc(temperaturesSize, sizeof(int));
    int *stack = malloc(temperaturesSize * sizeof(int));

    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {

        // Pop days whose warmer temperature is found
        while (top >= 0 &&
               temperatures[i] > temperatures[stack[top]]) {

            int prev = stack[top--];

            ans[prev] = i - prev;
        }

        // Store current day
        stack[++top] = i;
    }

    free(stack);

    *returnSize = temperaturesSize;
    return ans;
}