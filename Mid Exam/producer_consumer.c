#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define SIZE 10
#define MAX 100

int in=0, out=0, tsum=0;
int buffer[SIZE];
sem_t empty, full; // creating the semaphores that indicate empty or full 
pthread_mutex_t mutex; // to ensure mutual exclusion among the threads

void* producer(void* arg){
        for(int i = 0; i < MAX; i++){ // how many ever producers, max / p
                sem_wait(&empty); // acquire the semaphore named empty, wait till it is available
                // pthread_mutex_lock(&mutex); // once its empty, occupy it and start filling in mtuex manner

                buffer[in]=i+1;
                in=(in+1)%SIZE;

                // pthread_mutex_unlock(&mutex); // release the shared memory, once operation is complete
                sem_post(&full); // 
        }
        return NULL;
}

void* consumer(void* arg){
        for(int i = 0; i < MAX/4; i++){ // how many ever consumers, max / c
                sem_wait(&full);
                // pthread_mutex_lock(&mutex);

                int item=buffer[out];
                tsum+=item;
                out=(out+1)%SIZE;
                // printf("Consumer %d, consumed %d\n", id, item);

                // pthread_mutex_unlock(&mutex);
                sem_post(&empty);
        }
        return NULL;
}

int main(){
        pthread_t pro_thread, con_thread1, con_thread2, con_thread3, con_thread4;
        int con_id1 = 1, con_id2 = 2, con_id3 = 3, con_id4 = 4;

        sem_init(&empty, 0, 10);
        sem_init(&full, 0, 0);
        pthread_mutex_init(&mutex, 0);

        pthread_create(&pro_thread, 0, producer, 0);
        pthread_create(&con_thread1, 0, consumer, &con_id1);
        pthread_create(&con_thread2, 0, consumer, &con_id2);
        pthread_create(&con_thread3, 0, consumer, &con_id3);
        pthread_create(&con_thread4, 0, consumer, &con_id4);

        pthread_join(pro_thread, 0);
        pthread_join(con_thread1, 0);
        pthread_join(con_thread2, 0);
        pthread_join(con_thread3, 0);
        pthread_join(con_thread4, 0);

        printf("The sum is %d\n", tsum);

        // sem_destroy(&empty);
        // sem_destroy(&full);
        // pthread_mutex_destroy(&mutex);
        return 0;
}