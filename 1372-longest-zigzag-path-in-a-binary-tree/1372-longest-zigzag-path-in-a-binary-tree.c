/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int ans;

void dfs(struct TreeNode* root, int left, int right) {
    if (root == NULL)
        return;

    // Update maximum
    if (left > ans)
        ans = left;

    if (right > ans)
        ans = right;

    // If we go left now,
    // next move must be right
    if (root->left != NULL)
        dfs(root->left, right + 1, 0);

    // If we go right now,
    // next move must be left
    if (root->right != NULL)
        dfs(root->right, 0, left + 1);
}

int longestZigZag(struct TreeNode* root) {
    ans = 0;

    dfs(root, 0, 0);

    return ans;
}