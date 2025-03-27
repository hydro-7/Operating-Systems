#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t rw_mutex, mutex;
int no_reader=0;
int no_writer=0;

void *reader(void *arg){
    sem_wait(&mutex);
    no_reader++;
    if (no_reader==1){
        sem_wait(&rw_mutex);
    }
    sem_post(&mutex);
    printf("Reader %d reading\n",no_reader);
    sleep(1);
    sem_wait(&mutex);
    printf("Reader %d leaving\n",no_reader);
    no_reader--;
    if (no_reader==0){
        sem_post(&rw_mutex);
    }
    sem_post(&mutex);
}

void *writer(void *arg){
    sem_wait(&rw_mutex);
    no_writer++;
    printf("Writer %d write\n",no_writer);
    sleep(1);
    sem_post(&rw_mutex);
    printf("Writer %d leaving\n",no_writer);
    no_writer--;
}

int main(){
    pthread_t r1, r2, w1, r3, r4, w2, w3;
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&r3, NULL, reader, NULL);
    pthread_create(&w2, NULL, writer, NULL);
    pthread_create(&r4, NULL, reader, NULL);

    pthread_join(w1, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(r3, NULL);
    pthread_join(w2, NULL);
    pthread_join(r4, NULL);
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);
    return 0;
}

