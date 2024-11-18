#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure to hold the counter and mutex
typedef struct {
    int counter;
    pthread_mutex_t lock;
} ThreadData;

void* increment_counter(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    // Lock the mutex before accessing the shared resource
    pthread_mutex_lock(&data->lock);

    // Increment the counter
    data->counter++;
    printf("Counter value: %d\n", data->counter);

    // Unlock the mutex after accessing the shared resource
    pthread_mutex_unlock(&data->lock);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    ThreadData data;
    data.counter = 0;

    // Initialize the mutex
    if (pthread_mutex_init(&data.lock, NULL) != 0) {
        printf("Mutex init failed\n");
        return 1;
    }

    // Create two threads
    pthread_create(&thread1, NULL, increment_counter, &data);
    pthread_create(&thread2, NULL, increment_counter, &data);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&data.lock);

    return 0;
}
