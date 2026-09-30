int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check whether left child is a leaf
    if (root->left != NULL &&
        root->left->left == NULL &&
        root->left->right == NULL) {
        
        sum += root->left->val;
    }

    // Search both subtrees
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}