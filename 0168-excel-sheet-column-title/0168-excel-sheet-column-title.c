char* convertToTitle(int columnNumber) {
    char *ans = malloc(20);
    int k = 0;

    while (columnNumber > 0) {
        columnNumber--;

        ans[k++] = 'A' + (columnNumber % 26);

        columnNumber /= 26;
    }

    ans[k] = '\0';

    // Reverse
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