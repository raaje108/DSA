/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 */
int** findDifference(int* nums1, int nums1Size,
                     int* nums2, int nums2Size,
                     int* returnSize, int** returnColumnSizes) {

    int** result = malloc(2 * sizeof(int*));
    *returnColumnSizes = malloc(2 * sizeof(int));

    result[0] = malloc(nums1Size * sizeof(int));
    result[1] = malloc(nums2Size * sizeof(int));

    int size1 = 0, size2 = 0;

    // Elements present in nums1 but not nums2
    for (int i = 0; i < nums1Size; i++) {
        int found = 0;

        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                found = 1;
                break;
            }
        }

        // Avoid duplicates
        if (!found) {
            int duplicate = 0;

            for (int k = 0; k < size1; k++) {
                if (result[0][k] == nums1[i]) {
                    duplicate = 1;
                    break;
                }
            }

            if (!duplicate) {
                result[0][size1++] = nums1[i];
            }
        }
    }

    // Elements present in nums2 but not nums1
    for (int i = 0; i < nums2Size; i++) {
        int found = 0;

        for (int j = 0; j < nums1Size; j++) {
            if (nums2[i] == nums1[j]) {
                found = 1;
                break;
            }
        }

        // Avoid duplicates
        if (!found) {
            int duplicate = 0;

            for (int k = 0; k < size2; k++) {
                if (result[1][k] == nums2[i]) {
                    duplicate = 1;
                    break;
                }
            }

            if (!duplicate) {
                result[1][size2++] = nums2[i];
            }
        }
    }

    (*returnColumnSizes)[0] = size1;
    (*returnColumnSizes)[1] = size2;
    *returnSize = 2;

    return result;
}