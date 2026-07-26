int compress(char* chars, int charsSize) {
    int write = 0;
    int read = 0;

    while (read < charsSize) {
        char curr = chars[read];
        int count = 0;

        while (read < charsSize && chars[read] == curr) {
            read++;
            count++;
        }

        chars[write++] = curr;

        if (count > 1) {
            char temp[10];
            int len = 0;

            while (count > 0) {
                temp[len++] = (count % 10) + '0';
                count /= 10;
            }

            while (len > 0) {
                chars[write++] = temp[--len];
            }
        }
    }

    return write;
}