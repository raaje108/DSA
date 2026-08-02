#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool closeStrings(char* word1, char* word2) {
    int n1 = strlen(word1);
    int n2 = strlen(word2);

    if (n1 != n2)
        return false;

    int freq1[26] = {0};
    int freq2[26] = {0};

    // Count frequencies
    for (int i = 0; i < n1; i++) {
        freq1[word1[i] - 'a']++;
        freq2[word2[i] - 'a']++;
    }

    // Check both strings contain the same set of characters
    for (int i = 0; i < 26; i++) {
        if ((freq1[i] == 0) != (freq2[i] == 0))
            return false;
    }

    // Sort frequency arrays
    qsort(freq1, 26, sizeof(int), cmp);
    qsort(freq2, 26, sizeof(int), cmp);

    // Compare sorted frequencies
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i])
            return false;
    }

    return true;
}