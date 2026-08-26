#include <stdlib.h>

typedef struct {
    long long cost;
    int index;
} Worker;

/* Compare workers:
   smaller cost first,
   and if cost is equal, smaller index first.
*/
int compareWorker(Worker a, Worker b) {
    if (a.cost != b.cost)
        return a.cost < b.cost;

    return a.index < b.index;
}

/* ---------------- MIN HEAP ---------------- */

void heapifyUp(Worker heap[], int index) {

    while (index > 0) {

        int parent = (index - 1) / 2;

        if (compareWorker(heap[parent], heap[index]))
            break;

        Worker temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

void heapifyDown(Worker heap[], int size, int index) {

    while (1) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int smallest = index;

        if (left < size &&
            compareWorker(heap[left], heap[smallest])) {

            smallest = left;
        }

        if (right < size &&
            compareWorker(heap[right], heap[smallest])) {

            smallest = right;
        }

        if (smallest == index)
            break;

        Worker temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

void push(Worker heap[], int *size, Worker worker) {

    heap[*size] = worker;

    heapifyUp(heap, *size);

    (*size)++;
}

Worker pop(Worker heap[], int *size) {

    Worker result = heap[0];

    (*size)--;

    if (*size > 0) {

        heap[0] = heap[*size];

        heapifyDown(heap, *size, 0);
    }

    return result;
}

/* ---------------- SOLUTION ---------------- */

long long totalCost(
    int* costs,
    int costsSize,
    int k,
    int candidates
) {

    int n = costsSize;

    long long answer = 0;

    /* Special case:
       Candidate ranges overlap.
    */
    if (2 * candidates >= n) {

        Worker *heap =
            malloc(n * sizeof(Worker));

        int size = 0;

        for (int i = 0; i < n; i++) {

            Worker w = {
                costs[i],
                i
            };

            push(heap, &size, w);
        }

        for (int i = 0; i < k; i++) {

            Worker w = pop(heap, &size);

            answer += w.cost;
        }

        free(heap);

        return answer;
    }

    /* ---------------- NON-OVERLAPPING CASE ---------------- */

    Worker *leftHeap =
        malloc(candidates * sizeof(Worker));

    Worker *rightHeap =
        malloc(candidates * sizeof(Worker));

    int leftSize = 0;
    int rightSize = 0;

    int left = 0;
    int right = n - 1;

    /* Fill left candidates */
    for (int i = 0; i < candidates; i++) {

        Worker w = {
            costs[left],
            left
        };

        push(leftHeap, &leftSize, w);

        left++;
    }

    /* Fill right candidates */
    for (int i = 0; i < candidates; i++) {

        Worker w = {
            costs[right],
            right
        };

        push(rightHeap, &rightSize, w);

        right--;
    }

    /* Hire k workers */
    for (int hired = 0; hired < k; hired++) {

        if (leftSize > 0 && rightSize > 0) {

            if (compareWorker(
                    leftHeap[0],
                    rightHeap[0])) {

                Worker w =
                    pop(leftHeap, &leftSize);

                answer += w.cost;

                /* Add next worker from left */
                if (left <= right) {

                    Worker next = {
                        costs[left],
                        left
                    };

                    push(
                        leftHeap,
                        &leftSize,
                        next
                    );

                    left++;
                }

            } else {

                Worker w =
                    pop(rightHeap, &rightSize);

                answer += w.cost;

                /* Add next worker from right */
                if (left <= right) {

                    Worker next = {
                        costs[right],
                        right
                    };

                    push(
                        rightHeap,
                        &rightSize,
                        next
                    );

                    right--;
                }
            }
        }

        else if (leftSize > 0) {

            Worker w =
                pop(leftHeap, &leftSize);

            answer += w.cost;

        }

        else {

            Worker w =
                pop(rightHeap, &rightSize);

            answer += w.cost;
        }
    }

    free(leftHeap);
    free(rightHeap);

    return answer;
}