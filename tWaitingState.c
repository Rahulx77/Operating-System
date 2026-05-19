#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *firstThread(void *arg) {
    printf("Thread is now waiting for input...\n");
    getchar();
    printf("Input received, thread continues.\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, firstThread, NULL);
    pthread_join(thread, NULL);
    return 0;
}
