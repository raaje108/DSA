void getLeaves(struct TreeNode* root, int *arr, int *size) {

    if (root == NULL)
        return;

    // Check if leaf
    if (root->left == NULL && root->right == NULL) {
        arr[*size] = root->val;
        (*size)++;
        return;
    }

    // DFS: left first, then right
    getLeaves(root->left, arr, size);
    getLeaves(root->right, arr, size);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {

    int leaves1[200];
    int leaves2[200];

    int size1 = 0;
    int size2 = 0;

    getLeaves(root1, leaves1, &size1);
    getLeaves(root2, leaves2, &size2);

    // Different number of leaves
    if (size1 != size2)
        return false;

    // Compare leaf sequences
    for (int i = 0; i < size1; i++) {
        if (leaves1[i] != leaves2[i])
            return false;
    }

    return true;
}