#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_THREADS 5
#define DELAY 100 // 100 milliseconds

void* thread_function(void* arg) {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Simulate some work with a delay
    usleep(DELAY);

    gettimeofday(&end, NULL);

    long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    printf("Thread %ld elapsed time: %ld microseconds\n", (long)arg, elapsed);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, thread_function, (void*)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    return 0;
}
