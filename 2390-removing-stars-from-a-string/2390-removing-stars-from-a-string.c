char* removeStars(char* s) {
    int len = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '*') {
            if (len > 0)
                len--;       // remove previous character
        } else {
            s[len++] = s[i]; // keep character
        }
    }

    s[len] = '\0';

    return s;
}