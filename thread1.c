#include <stdio.h>
#include <pthread.h>

void *myThread(void *arg) {
    printf("Thread is running!\n");
    return NULL;
}

int main() {
    pthread_t thread;

    // Creates a thread object in memory. This thread is in New state (conceptually).
    printf("Thread object created (New State)\n");

    pthread_create(&thread, NULL, myThread, NULL);
    // Starts the thread. After this call, the thread moves from New -> Runnable.

    pthread_join(thread, NULL); // Main program waits until the thread finishes.

    return 0;
}
