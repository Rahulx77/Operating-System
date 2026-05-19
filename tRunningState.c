#include <stdio.h>
#include <pthread.h>

void *firstThread(void *arg) {
    printf("Thread is now Running and using CPU.\n");
    for (int i = 0; i < 10; i++) {
        printf("Running: %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, firstThread, NULL);
    pthread_join(thread, NULL);
    return 0;
}
