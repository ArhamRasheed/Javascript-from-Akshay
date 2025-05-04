/*1. Create two threads that increment a global counter 1000 times each. Use a mutex to avoid race
conditions and print the final result.*/


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_ITERATIONS 1000

int counter = 0;
//pthread_mutex_t lock;
sem_t lock;

void *increment(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        //pthread_mutex_lock(&lock);
        sem_wait(&lock);
        counter++;
        sem_post(&lock);
        //pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize the mutex
    //pthread_mutex_init(&lock, NULL);
    sem_init(&lock, 0, 1);

    // Create two threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy the mutex
    //pthread_mutex_destroy(&lock);
    sem_destroy(&lock)

    // Print the final value of counter
    printf("Final counter value: %d\n", counter);

    return 0;
}
