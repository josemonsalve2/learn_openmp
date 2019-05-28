#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

    #pragma omp parallel
    {
        printf("Hello, I am %d\n", omp_get_thread_num());
        #pragma omp master
        {
            printf("This only once from %d\n", omp_get_thread_num());
        }
    }
    return 0;
}