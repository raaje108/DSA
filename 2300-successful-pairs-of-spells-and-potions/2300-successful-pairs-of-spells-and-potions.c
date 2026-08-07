#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* successfulPairs(int* spells, int spellsSize,
                     int* potions, int potionsSize,
                     long long success, int* returnSize) {

    qsort(potions, potionsSize, sizeof(int), compare);

    int *ans = malloc(spellsSize * sizeof(int));

    for (int i = 0; i < spellsSize; i++) {
        int low = 0;
        int high = potionsSize;

        // Find first potion such that:
        // spells[i] * potions[mid] >= success
        while (low < high) {
            int mid = low + (high - low) / 2;

            if ((long long)spells[i] * potions[mid] >= success)
                high = mid;
            else
                low = mid + 1;
        }

        ans[i] = potionsSize - low;
    }

    *returnSize = spellsSize;
    return ans;
}