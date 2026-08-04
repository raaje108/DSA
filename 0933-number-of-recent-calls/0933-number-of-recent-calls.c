typedef struct {
    int times[10000];
    int front;
    int rear;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = malloc(sizeof(RecentCounter));

    obj->front = 0;
    obj->rear = 0;

    return obj;
}


int recentCounterPing(RecentCounter* obj, int t) {
    obj->times[obj->rear++] = t;

    // Remove calls older than t - 3000
    while (obj->front < obj->rear &&
           obj->times[obj->front] < t - 3000) {
        obj->front++;
    }

    return obj->rear - obj->front;
}


void recentCounterFree(RecentCounter* obj) {
    free(obj);
}