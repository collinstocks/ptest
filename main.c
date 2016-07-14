#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>


void * worker (void * argument) {
    printf("message from thread\n");
    return NULL;
}


int main () {
    pthread_t thread;
    int result_code;

    printf("starting thread\n");

    result_code = pthread_create(&thread, NULL, worker, NULL);
    assert(0 == result_code);

    result_code = pthread_join(thread, NULL);
    printf("thread exited\n");

    return 0;
}
