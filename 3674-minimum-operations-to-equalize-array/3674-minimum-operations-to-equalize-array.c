int minOperations(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[0]) {
            return 1;
        }
    }

    return 0;
}