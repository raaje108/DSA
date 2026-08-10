#include <stdlib.h>

void solve(int start, int k, int target,
           int *temp, int size,
           int **ans, int *returnSize,
           int *returnColumnSizes) {

    if (size == k) {
        if (target == 0) {
            ans[*returnSize] = malloc(k * sizeof(int));

            for (int i = 0; i < k; i++)
                ans[*returnSize][i] = temp[i];

            returnColumnSizes[*returnSize] = k;
            (*returnSize)++;
        }
        return;
    }

    for (int i = start; i <= 9; i++) {
        if (i > target)
            break;

        temp[size] = i;

        solve(i + 1, k, target - i,
             temp, size + 1,
             ans, returnSize, returnColumnSizes);
    }
}

int** combinationSum3(int k, int n,
                      int* returnSize,
                      int** returnColumnSizes) {

    *returnSize = 0;

    int maxCombinations = 1000;

    int **ans = malloc(maxCombinations * sizeof(int *));
    *returnColumnSizes = malloc(maxCombinations * sizeof(int));

    int temp[9];

    solve(1, k, n, temp, 0,
          ans, returnSize, *returnColumnSizes);

    return ans;
}