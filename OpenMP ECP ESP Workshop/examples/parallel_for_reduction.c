#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10

int main() {
    int x = 5;
    #pragma omp parallel for reduction(+:x)
    for (int i = 0; i < N; i++) {
        printf("Thread %d, x=%d, address %p\n", omp_get_thread_num(), x, &x);
        x = i;
    }
    printf("The final value of x is %d\n",x);
    return 0;
}