#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    int len = strlen(s);

    int* numStack = malloc(len * sizeof(int));
    char** strStack = malloc(len * sizeof(char*));

    int top = -1;
    int num = 0;

    char* current = malloc(10001);
    current[0] = '\0';

    for (int i = 0; i < len; i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        else if (s[i] == '[') {
            // Store number and current string
            top++;
            numStack[top] = num;
            strStack[top] = current;

            // Start a new string
            current = malloc(10001);
            current[0] = '\0';
            num = 0;
        }

        else if (s[i] == ']') {
            int repeat = numStack[top];
            char* previous = strStack[top];
            top--;

            char* temp = malloc(10001);
            temp[0] = '\0';

            // Repeat current string
            for (int j = 0; j < repeat; j++) {
                strcat(temp, current);
            }

            strcat(previous, temp);

            free(current);
            free(temp);

            current = previous;
        }

        else {
            // Normal character
            int l = strlen(current);
            current[l] = s[i];
            current[l + 1] = '\0';
        }
    }

    free(numStack);
    free(strStack);

    return current;
}