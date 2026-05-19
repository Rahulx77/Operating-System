#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;

void *firstThread(void *arg) {
    pthread_mutex_lock(&lock);
    printf("Thread 1 acquired lock and working...\n");
    sleep(5);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *secondThread(void *arg) {
    sleep(1);
    printf("Thread 2 trying to acquire lock....\n");
    pthread_mutex_lock(&lock);
    printf("Thread 2 acquired lock after Thread 1 released it.\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, firstThread, NULL);
    pthread_create(&t2, NULL, secondThread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
