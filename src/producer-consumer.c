#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define M 8
#define N 10

#include <semaphore.h>

typedef unsigned int semaforo;

sem_t cliente, servidor, mutex;
int buffer[N], free_pos = 0;
int count = 0;

int generate_reg() {
    sleep(1);
    printf("generate reg\n");
    return rand();
}

void insert_reg(int reg) {
    sleep(1);
    buffer[free_pos++] = reg;
    printf("insert register\n");
}

int *read_buffer() {
    sleep(1);
    printf("read buffer\n");
    return buffer;
}

void *clean_buffer() {
    sleep(1);
    printf("clear buffer\n");
    free_pos = 0;
}

void process_reg() {
    sleep(1);
    printf("process register\n");
}

void *client(void *unused) {
    while (1) {
        if (count == 3) {
            sem_post(&servidor);
            count = 0;
        }

        int reg = generate_reg();

        sem_wait(&cliente);
        insert_reg(reg);

        sem_wait(&mutex);
        count++;
        sem_post(&mutex);
    }
}

void *server(void *unused) {
    while (1) {
        sem_wait(&servidor);
        read_buffer();
        clean_buffer();

        sem_destroy(&cliente);
        sem_init(&cliente, 0, M);
    }
}

int main(void) {
    pthread_t threads[11];

    // init semaphores
    sem_init(&cliente, 0, M);
    sem_init(&servidor, 0, 0);
    sem_init(&mutex, 0, 1);

    // create server process
    pthread_create(&threads[0], NULL, &server, NULL);

    // create 10 clients
    for (int i = 1; i <= 10; i++)
        pthread_create(&threads[i], NULL, &client, NULL);

    // launch threads
    for (int i = 0; i <= 10; i++) pthread_join(threads[i], NULL);

    return 0;
}
