#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;

    // Get the current time before sleeping
    gettimeofday(&start, NULL);

    // Sleep for 1 second (1,000,000 microseconds)
    usleep(1);

    // Get the current time after sleeping
    gettimeofday(&end, NULL);

    // Calculate the elapsed time in microseconds
    long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    printf("Elapsed time: %ld microseconds\n", elapsed);

    return 0;
}
