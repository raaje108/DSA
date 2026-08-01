#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    int freq[2001] = {0};
    
    // Count frequency of each number
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i] + 1000]++;
    }

    // Check whether two numbers have the same frequency
    for (int i = 0; i < 2001; i++) {
        if (freq[i] == 0)
            continue;

        for (int j = i + 1; j < 2001; j++) {
            if (freq[i] == freq[j])
                return false;
        }
    }

    return true;
}