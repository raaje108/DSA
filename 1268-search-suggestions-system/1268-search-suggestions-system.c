#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

char ***suggestedProducts(char **products, int productsSize,
                          char *searchWord, int *returnSize,
                          int **returnColumnSizes) {

    // Sort products
    qsort(products, productsSize, sizeof(char *), cmp);

    int m = strlen(searchWord);

    *returnSize = m;

    *returnColumnSizes = malloc(m * sizeof(int));

    char ***ans = malloc(m * sizeof(char **));

    char prefix[1005];

    for (int i = 0; i < m; i++) {

        // Build prefix
        prefix[i] = searchWord[i];
        prefix[i + 1] = '\0';

        ans[i] = malloc(3 * sizeof(char *));
        (*returnColumnSizes)[i] = 0;

        // Find first product >= prefix
        int left = 0, right = productsSize - 1;
        int pos = productsSize;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (strcmp(products[mid], prefix) >= 0) {
                pos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Take at most 3 matching products
        for (int j = pos; j < productsSize && 
             (*returnColumnSizes)[i] < 3; j++) {

            if (strncmp(products[j], prefix, i + 1) == 0) {
                ans[i][(*returnColumnSizes)[i]] = products[j];
                (*returnColumnSizes)[i]++;
            } else {
                break;
            }
        }
    }

    return ans;
}