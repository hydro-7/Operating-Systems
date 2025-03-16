#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define SIZE 10
#define MAX 100

int in=0, out=0, tsum=0;
int buffer[SIZE];
sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* arg){
        for(int i=0; i<MAX; i++){
                sem_wait(&empty);
                pthread_mutex_lock(&mutex);

                buffer[in]=i+1;
                // printf("The producer produced: %d\n",i+1);
                in=(in+1)%SIZE;

                pthread_mutex_unlock(&mutex);
                sem_post(&full);
        }
        return NULL;
}

void* consumer(void* arg){
        int id= (int)arg;
        for(int i=0;i<MAX/2;i++){
                sem_wait(&full);
                pthread_mutex_lock(&mutex);

                int item=buffer[out];
                tsum+=item;
                out=(out+1)%SIZE;
                // printf("Consumer %d, consumed %d\n", id, item);

                pthread_mutex_unlock(&mutex);
                sem_post(&empty);
        }
        return NULL;
}

int main(){
        pthread_t pro_thread, con_thread1, con_thread2;
        int con_id1=1, con_id2=2;

        sem_init(&empty, 0, 10);
        sem_init(&full, 0, 0);
        pthread_mutex_init(&mutex, 0);

        pthread_create(&pro_thread, 0, producer, 0);
        pthread_create(&con_thread1, 0, consumer, &con_id1);
        pthread_create(&con_thread2, 0, consumer, &con_id2);

        pthread_join(pro_thread, 0);
        pthread_join(con_thread1, 0);
        pthread_join(con_thread2, 0);

        sem_destroy(&empty);
        sem_destroy(&full);
        pthread_mutex_destroy(&mutex);

        printf("The sum is %d\n", tsum);
        return 0;
}
