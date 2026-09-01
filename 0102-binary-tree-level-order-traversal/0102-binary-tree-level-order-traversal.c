/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    if(root == NULL){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int capacity = 2000;

    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    *returnSize = 0;

    while(front < rear){

        int levelSize = rear - front;

        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for(int i = 0; i < levelSize; i++){

            struct TreeNode* node = queue[front++];

            result[*returnSize][i] = node->val;

            if(node->left)
                queue[rear++] = node->left;

            if(node->right)
                queue[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return result;
}