#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *firstThread(void *arg) {
    // It must return void and take one argument void *arg (because of POSIX thread rules).
    printf("Thread is running...\n");
    sleep(2); // Simulate work
    printf("Thread finished running.\n");
    pthread_exit(NULL); // pthread_exit(NULL) tells the OS the thread is done and releases thread resources properly.
}

int main() {
    pthread_t thread; // pthread_t is used to store thread IDs.

    pthread_create(&thread, NULL, firstThread, NULL);
    // &thread  - Address where the new thread ID will be stored.
    // NULL     - No special attributes (default settings).
    // firstThread - The function the thread will run.
    // NULL     - No arguments passed to firstThread.
    // Thread becomes Runnable (ready to run).

    printf("Thread is created and now Runnable (waiting for CPU)\n");

    pthread_join(thread, NULL); // blocks the main program until thread is complete.

    return 0;
}
