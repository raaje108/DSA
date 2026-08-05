#include <stdlib.h>
#include <limits.h>

int maxLevelSum(struct TreeNode* root) {
    // Queue for BFS
    struct TreeNode** queue = malloc(10000 * sizeof(struct TreeNode*));

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int level = 1;
    int bestLevel = 1;
    int maxSum = INT_MIN;

    while (front < rear) {
        int levelSize = rear - front;
        int sum = 0;

        // Process current level
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            sum += node->val;

            if (node->left != NULL)
                queue[rear++] = node->left;

            if (node->right != NULL)
                queue[rear++] = node->right;
        }

        // Update maximum
        if (sum > maxSum) {
            maxSum = sum;
            bestLevel = level;
        }

        level++;
    }

    free(queue);

    return bestLevel;
}