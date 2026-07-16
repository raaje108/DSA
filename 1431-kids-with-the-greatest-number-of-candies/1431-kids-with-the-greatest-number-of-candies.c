/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;

    bool *ans = (bool *)malloc(sizeof(bool) * candiesSize);

    int maxCandy = candies[0];
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > maxCandy)
            maxCandy = candies[i];
    }

    for (int i = 0; i < candiesSize; i++) {
        ans[i] = (candies[i] + extraCandies >= maxCandy);
    }

    return ans;
}