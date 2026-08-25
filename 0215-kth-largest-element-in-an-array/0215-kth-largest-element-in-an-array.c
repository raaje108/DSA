#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int *heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapifyDown(int *heap, int size, int i) {
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int *heap = malloc(k * sizeof(int));
    int size = 0;

    for (int i = 0; i < numsSize; i++) {

        if (size < k) {
            heap[size] = nums[i];
            heapifyUp(heap, size);
            size++;
        }
        else if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }

    int ans = heap[0];

    free(heap);

    return ans;
}