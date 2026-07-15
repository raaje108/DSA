#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    // Check if str1 + str2 == str2 + str1
    char *s1 = (char *)malloc(n1 + n2 + 1);
    char *s2 = (char *)malloc(n1 + n2 + 1);

    strcpy(s1, str1);
    strcat(s1, str2);

    strcpy(s2, str2);
    strcat(s2, str1);

    if (strcmp(s1, s2) != 0) {
        free(s1);
        free(s2);
        char *ans = (char *)malloc(1);
        ans[0] = '\0';
        return ans;
    }

    free(s1);
    free(s2);

    int len = gcd(n1, n2);

    char *ans = (char *)malloc(len + 1);
    strncpy(ans, str1, len);
    ans[len] = '\0';

    return ans;
}