#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {

    int lenA = strlen(a);
    int lenB = strlen(b);

    int maxLen = (lenA > lenB ? lenA : lenB);

    // +2 = possible carry + '\0'
    char *ans = malloc(maxLen + 2);

    int i = lenA - 1;
    int j = lenB - 1;
    int k = 0;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';

        if (j >= 0)
            sum += b[j--] - '0';

        ans[k++] = (sum % 2) + '0';

        carry = sum / 2;
    }

    ans[k] = '\0';

    // Reverse answer
    int left = 0;
    int right = k - 1;

    while (left < right) {
        char temp = ans[left];
        ans[left] = ans[right];
        ans[right] = temp;

        left++;
        right--;
    }

    return ans;
}