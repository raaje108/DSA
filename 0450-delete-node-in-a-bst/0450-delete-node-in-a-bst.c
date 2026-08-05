struct TreeNode* deleteNode(struct TreeNode* root, int key) {

    if (root == NULL)
        return NULL;

    // Search for the node
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node found

        // Case 1: No left child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: No right child
        if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct TreeNode* temp = root->right;

        // Find smallest node in right subtree
        while (temp->left != NULL)
            temp = temp->left;

        // Replace current value
        root->val = temp->val;

        // Delete the duplicate node
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}