#include <stdlib.h>

int change(int amount, int* coins, int coinsSize) {
    // Allocate a 1D DP array of size (amount + 1) and initialize to 0
    // calloc is used here to automatically handle the zero-initialization
    // dp[i] represents the number of ways to make up amount i
    int* dp = (int*)calloc(amount + 1, sizeof(int));
    if (dp == NULL) {
        return 0; // Handle memory allocation failure
    }
    
    // Base case: There is exactly 1 way to make up an amount of 0 (by using no coins)
    dp[0] = 1;
    
    // Iterate through each coin
    for (int i = 0; i < coinsSize; i++) {
        // Update the dp array for all amounts greater than or equal to the current coin
        for (int j = coins[i]; j <= amount; j++) {
            // The number of ways to make amount j includes the ways to make it 
            // WITHOUT this coin (already in dp[j]) PLUS the ways to make amount (j - coin)
            // Cast to unsigned int prevents potential signed integer overflow undefined behavior 
            // during intermediate additions, though LeetCode guarantees the final result fits in a 32-bit int.
            dp[j] = (unsigned int)dp[j] + dp[j - coins[i]];
        }
    }
    
    // Store the result before freeing the allocated memory
    int result = dp[amount];
    
    // Always free dynamically allocated memory to prevent leaks
    free(dp);
    
    return result;
}