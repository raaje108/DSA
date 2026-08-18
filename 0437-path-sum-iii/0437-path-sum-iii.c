/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    long long sum;
    int count;
} Entry;

Entry map[100000];
int mapSize;

void add(long long sum, int value) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].sum == sum) {
            map[i].count += value;
            return;
        }
    }

    map[mapSize].sum = sum;
    map[mapSize].count = value;
    mapSize++;
}

int get(long long sum) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].sum == sum)
            return map[i].count;
    }

    return 0;
}

int dfs(struct TreeNode* root, long long sum, int targetSum) {
    if (root == NULL)
        return 0;

    sum += root->val;

    int ans = get(sum - targetSum);

    add(sum, 1);

    ans += dfs(root->left, sum, targetSum);
    ans += dfs(root->right, sum, targetSum);

    add(sum, -1);

    return ans;
}

int pathSum(struct TreeNode* root, int targetSum) {
    mapSize = 0;

    // Prefix sum 0 exists once.
    add(0, 1);

    return dfs(root, 0, targetSum);
}