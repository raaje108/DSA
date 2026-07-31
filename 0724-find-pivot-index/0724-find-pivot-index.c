int pivotIndex(int* nums, int numsSize) {
    int total = 0;
    int left = 0;

    // Find total sum
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    // Find pivot index
    for (int i = 0; i < numsSize; i++) {
        if (left == total - left - nums[i]) {
            return i;
        }

        left += nums[i];
    }

    return -1;
}