#include <stdlib.h>

typedef struct {
    int n2;
    int n1;
} Pair;

/* ---------- Pair sorting ---------- */

int compare(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;

    return p2->n2 - p1->n2;   // descending nums2
}

/* ---------- Min Heap ---------- */

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;

    heapifyUp(heap, *size);

    (*size)++;
}

int pop(int heap[], int *size) {
    int result = heap[0];

    (*size)--;

    if (*size > 0) {
        heap[0] = heap[*size];
        heapifyDown(heap, *size, 0);
    }

    return result;
}

/* ---------- Main Solution ---------- */

long long maxScore(int* nums1, int nums1Size,
                   int* nums2, int nums2Size,
                   int k) {

    Pair *pairs = malloc(nums1Size * sizeof(Pair));

    for (int i = 0; i < nums1Size; i++) {
        pairs[i].n1 = nums1[i];
        pairs[i].n2 = nums2[i];
    }

    /* Sort by nums2 descending */
    qsort(pairs, nums1Size, sizeof(Pair), compare);

    int *heap = malloc(nums1Size * sizeof(int));

    int heapSize = 0;
    long long sum = 0;
    long long answer = 0;

    for (int i = 0; i < nums1Size; i++) {

        /* Add current nums1 */
        push(heap, &heapSize, pairs[i].n1);
        sum += pairs[i].n1;

        /*
         * Keep only the largest k nums1 values.
         * Since this is a min heap, heap[0] is the smallest.
         */
        if (heapSize > k) {
            int removed = pop(heap, &heapSize);
            sum -= removed;
        }

        /*
         * Now we have exactly k elements.
         *
         * Because pairs are sorted by nums2 descending,
         * pairs[i].n2 is the minimum nums2 among these elements.
         */
        if (heapSize == k) {
            long long score = sum * pairs[i].n2;

            if (score > answer)
                answer = score;
        }
    }

    free(heap);
    free(pairs);

    return answer;
}