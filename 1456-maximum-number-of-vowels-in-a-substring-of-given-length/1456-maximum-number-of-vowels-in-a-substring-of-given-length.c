#include <stdbool.h>

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u';
}

int maxVowels(char* s, int k) {
    int count = 0;

    // Count vowels in the first window
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i]))
            count++;
    }

    int maxCount = count;

    // Slide the window
    for (int i = k; s[i] != '\0'; i++) {
        if (isVowel(s[i]))
            count++;
        if (isVowel(s[i - k]))
            count--;

        if (count > maxCount)
            maxCount = count;
    }

    return maxCount;
}