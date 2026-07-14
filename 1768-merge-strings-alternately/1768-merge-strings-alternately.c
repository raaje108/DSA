#include <stdlib.h>
#include <string.h>

char* mergeAlternately(char* word1, char* word2) {
    int n1 = strlen(word1);
    int n2 = strlen(word2);

    char *ans = (char *)malloc(n1 + n2 + 1);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        ans[k++] = word1[i++];
        ans[k++] = word2[j++];
    }

    while (i < n1)
        ans[k++] = word1[i++];

    while (j < n2)
        ans[k++] = word2[j++];

    ans[k] = '\0';

    return ans;
}