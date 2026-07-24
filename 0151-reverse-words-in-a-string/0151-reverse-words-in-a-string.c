void reverse(char *s, int l, int r) {
    while (l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s);
    int i = 0, j = 0;

    // Remove leading, trailing, and extra spaces
    while (i < n) {
        while (i < n && s[i] == ' ')
            i++;

        while (i < n && s[i] != ' ')
            s[j++] = s[i++];

        while (i < n && s[i] == ' ')
            i++;

        if (i < n)
            s[j++] = ' ';
    }

    s[j] = '\0';

    // Reverse entire string
    reverse(s, 0, j - 1);

    // Reverse each word
    int start = 0;
    for (i = 0; i <= j; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }

    return s;
}