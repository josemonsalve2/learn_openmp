#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int x = 5;
    #pragma omp parallel private(x)
    {
        printf("Thread %d, x=%d, address %p\n", omp_get_thread_num(), x, &x);
    }
    return 0;
}