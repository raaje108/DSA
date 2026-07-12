int findTargetSumWays(int* nums, int numsSize, int target) {
    int sum = 0;

    for (int i = 0; i < numsSize; i++)
        sum += nums[i];

    if (abs(target) > sum)
        return 0;

    if ((sum + target) % 2 != 0)
        return 0;

    int subset = (sum + target) / 2;

    int dp[subset + 1];

    for (int i = 0; i <= subset; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 0; i < numsSize; i++) {
        for (int j = subset; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[subset];
}