#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

static int count = 10;

void *thread1_routine(void *unused) {
    printf("hello from thread 1\n");
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }
}

void *thread2_routine(void *unused) {
    printf("hello from thread 2\n ");
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        count--;
        pthread_mutex_unlock(&mutex);
    }
}

void errorExit(char *strerr) {
    perror(strerr);
    exit(1);
}

// gcc -pthread main.c -o main
int main(int argc, char *argv[]) {
    pthread_t thread1, thread2;

    if (0 != pthread_create(&thread1, NULL, &thread1_routine, NULL))
        errorExit("thread 1 cannot be created");

    if (0 != pthread_create(&thread2, NULL, &thread2_routine, NULL))
        errorExit("thread 2 cannot be created");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("count value %d \n", count);

    return 0;
}
