#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t tid[2];

void* doSomeThing(void *arg) {
    unsigned long i = 0;

    pthread_t id = pthread_self();
    if(pthread_equal(id, tid[0])) 
    {
        fprintf(stderr, "First thread processing\n");
    } else {
        fprintf(stderr, "Second thread processing\n");
    }

    for(i = 0; i<(0xFFFFFFFF); i++);
    return NULL;
}

int main(void) 
{
    int i =0;
    int err;
    while(i < 2) 
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0) 
            fprintf(stderr, "cant create thread :[%s]", strerror(err));
        else 
            fprintf(stderr, "Thread create successfully");
        i++;
    }

    // Menunggu kedua thread selesai
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    fprintf(stderr, "Both threads have finished processing.\n");

    return 0;
}

