/*
Q1. You are developing a scientific computation application that processes large datasets. One
of the tasks is to calculate the element-wise sum of two large arrays (each of size 10 million
elements) and store the result in a third array. Due to performance requirements, your manager
suggests using multithreading to optimize the processing time.
You decide to:
 First, write a simple serial (single-threaded) version of the program.
 Then, write a concurrent version using 10 worker threads, where each thread handles
an equal portion of the arrays.
Tasks:
1. Explain how you would divide the work among 10 threads.
2. How would you pass the necessary parameters (like array pointers and indices) to each
thread?
3. What synchronization issues, if any, could arise in this case?
4. Write a pseudocode outline showing the thread creation and division of array work.
5. Compare and discuss the expected performance difference between the serial and
concurrent versions.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

#define array_size 10000000
#define Total_threads 10

int *array1;
int *array2;
int *array3;


void* sum(void* arg){
    int thread_id = *((int*)arg);
    int start = thread_id * (array_size/Total_threads);
    int end = start + (array_size/Total_threads);

    for(int i=start; i<end; i++){
        //printf("%d ", i);
        array3[i] = array1[i] + array2[i];
    }

    return NULL;
}

int main(){
    pthread_t threads[Total_threads];
    int thread_ids[Total_threads];
    array1 = malloc(sizeof(int)*array_size);
    array2 = malloc(sizeof(int)*array_size);
    array3 = malloc(sizeof(int)*array_size);
    //initializing arrays
    for(int i=0; i<array_size; i++){
       array1[i] = 100;
       array2[i] = 200;
       array3[i] = 0;
    }

    for(int i=0; i<10; i++){
        // printf("hi");
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sum, (void*)&thread_ids[i]);
        
    }

    for(int i=0; i<10; i++){
        pthread_join(threads[i], NULL);
    }
    
    for(int i=0; i<10; i++){
        printf("%d, ", array3[i]);
    }

    free(array1);
    free(array2);
    free(array3);
    
    return 0;
}

