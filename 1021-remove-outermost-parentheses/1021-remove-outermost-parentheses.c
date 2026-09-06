char* removeOuterParentheses(char* s) {
    int depth = 0;
    int n = strlen(s);

    char* ans = (char*)malloc((n + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(') {
            depth++;

            // Not an outermost '('
            if (depth > 1) {
                ans[j++] = s[i];
            }
        }
        else {
            depth--;

            // Not an outermost ')'
            if (depth > 0) {
                ans[j++] = s[i];
            }
        }
    }

    ans[j] = '\0';

    return ans;
}