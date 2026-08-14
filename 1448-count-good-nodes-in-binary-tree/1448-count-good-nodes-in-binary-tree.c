int dfs(struct TreeNode* root, int maxValue) {

    if (root == NULL)
        return 0;

    int good = 0;

    // Check if current node is good
    if (root->val >= maxValue)
        good = 1;

    // Update maximum value on this path
    if (root->val > maxValue)
        maxValue = root->val;

    // Check left and right subtrees
    good += dfs(root->left, maxValue);
    good += dfs(root->right, maxValue);

    return good;
}

int goodNodes(struct TreeNode* root) {

    return dfs(root, root->val);
}