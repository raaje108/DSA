#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool uniqueOccurrences(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);

    int freq[1001] = {0};
    int freqSize = 0;

    int i = 0;

    while (i < arrSize) {
        int j = i;

        // j moves until a different number is found
        while (j < arrSize && arr[j] == arr[i]) {
            j++;
        }

        int count = j - i;

        // Check if this frequency already exists
        for (int k = 0; k < freqSize; k++) {
            if (freq[k] == count)
                return false;
        }

        freq[freqSize++] = count;

        i = j;
    }

    return true;
}