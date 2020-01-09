#include <stdio.h>
#include <pthread.h>
#include <locale.h>

#define NUMTHREADS 4

long long sum0, sum1, sum2, sum3;

void *runner0(void *param) {
    long long i;
    sum0 = 0;
    for (i = 1; i < 1000000000; i++) {
        sum0 += i;
    }
    pthread_exit(0);
}

void *runner1(void *param) {
    long long i;
    sum1 = 0;
    for (i = 1000000000; i < 2000000000; i++) {
        sum1 += i;
    }
    pthread_exit(0);
}

void *runner2(void *param) {
    long long i;
    sum2 = 0;
    for (i = 2000000000; i < 3000000000; i++) {
        sum2 += i;
    }
    pthread_exit(0);
}

void *runner3(void *param) {
    long long i;
    sum3 = 0;
    for (i = 3000000000; i <= 4000000000; i++) {
        sum3 += i;
    }
    pthread_exit(0);
}

int main() {
    pthread_t tid[NUMTHREADS];  // thread IDs
    pthread_attr_t attr[NUMTHREADS];    // set of attributes for threads

    int i;

    // get default attributes
    for (i = 0; i < NUMTHREADS; i++) {
        pthread_attr_init(&attr[i]);
    }

    // create threads
    pthread_create(&tid[0], &attr[0], runner0, NULL);
    pthread_create(&tid[1], &attr[1], runner1, NULL);
    pthread_create(&tid[2], &attr[2], runner2, NULL);
    pthread_create(&tid[3], &attr[3], runner3, NULL);

    // now wait for them all to exit
    for (i = 0; i < NUMTHREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    setlocale(LC_NUMERIC, "");  // allow for commas

    printf("sum = %'lld\n", sum0 + sum1 + sum2 + sum3);

    return 0;
}