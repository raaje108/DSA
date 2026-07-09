int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int mn = matrix[i + 1][j];

            if (j > 0 && matrix[i + 1][j - 1] < mn)
                mn = matrix[i + 1][j - 1];

            if (j < n - 1 && matrix[i + 1][j + 1] < mn)
                mn = matrix[i + 1][j + 1];

            matrix[i][j] += mn;
        }
    }

    int ans = matrix[0][0];
    for (int j = 1; j < n; j++) {
        if (matrix[0][j] < ans)
            ans = matrix[0][j];
    }

    return ans;
}