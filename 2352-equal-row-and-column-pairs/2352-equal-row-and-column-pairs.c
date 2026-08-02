int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int n = gridSize;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int k;

            // Compare row i with column j
            for (k = 0; k < n; k++) {
                if (grid[i][k] != grid[k][j])
                    break;
            }

            if (k == n)
                count++;
        }
    }

    return count;
}