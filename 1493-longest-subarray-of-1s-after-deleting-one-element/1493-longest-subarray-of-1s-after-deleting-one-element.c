int longestSubarray(int* nums, int numsSize) {
    int left = 0;
    int zeros = 0;
    int maxLen = 0;

    for (int right = 0; right < numsSize; right++) {

        if (nums[right] == 0)
            zeros++;

        // We can have at most one zero
        while (zeros > 1) {
            if (nums[left] == 0)
                zeros--;
            left++;
        }

        // Delete one element, so subtract 1
        int len = right - left;

        if (len > maxLen)
            maxLen = len;
    }

    return maxLen;
}