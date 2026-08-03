int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = malloc(asteroidsSize * sizeof(int));
    int top = 0;

    for (int i = 0; i < asteroidsSize; i++) {
        int current = asteroids[i];

        // Collision happens only when:
        // stack top is moving right (+)
        // current is moving left (-)
        while (top > 0 && stack[top - 1] > 0 && current < 0) {
            
            if (stack[top - 1] < -current) {
                // Top asteroid explodes
                top--;
                continue;
            }
            
            else if (stack[top - 1] == -current) {
                // Both explode
                top--;
                current = 0;
            }
            
            else {
                // Current asteroid explodes
                current = 0;
            }
        }

        if (current != 0) {
            stack[top++] = current;
        }
    }

    *returnSize = top;
    return stack;
}