#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

    #pragma omp parallel
    {
        printf("Hi from %d\n", omp_get_thread_num());
        #pragma omp barrier
        printf("Bye from %d\n", omp_get_thread_num());
    }
    return 0;
}