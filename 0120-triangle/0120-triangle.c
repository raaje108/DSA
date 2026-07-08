int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int dp[triangleSize + 1];

    for (int i = 0; i <= triangleSize; i++)
        dp[i] = 0;

    for (int i = triangleSize - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (dp[j] < dp[j + 1])
                dp[j] = triangle[i][j] + dp[j];
            else
                dp[j] = triangle[i][j] + dp[j + 1];
        }
    }

    return dp[0];
}