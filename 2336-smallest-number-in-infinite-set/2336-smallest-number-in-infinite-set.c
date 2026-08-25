#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *heap;
    int size;
    int capacity;

    bool *present;
    int next;
} SmallestInfiniteSet;

SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet* obj = malloc(sizeof(SmallestInfiniteSet));

    obj->capacity = 1000;
    obj->size = 0;
    obj->next = 1;

    obj->heap = malloc(obj->capacity * sizeof(int));
    obj->present = calloc(1001, sizeof(bool));

    return obj;
}

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

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    
    // If we have numbers added back
    if (obj->size > 0) {
        int ans = obj->heap[0];

        obj->heap[0] = obj->heap[obj->size - 1];
        obj->size--;

        heapifyDown(obj->heap, obj->size, 0);

        obj->present[ans] = false;

        return ans;
    }

    // Otherwise return the next unused number
    return obj->next++;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    
    // num must be smaller than next
    if (num >= obj->next)
        return;

    // Already present
    if (obj->present[num])
        return;

    obj->heap[obj->size] = num;
    obj->size++;

    obj->present[num] = true;

    heapifyUp(obj->heap, obj->size - 1);
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj->heap);
    free(obj->present);
    free(obj);
}