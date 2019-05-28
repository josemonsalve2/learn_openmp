#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10
int main() {
    #pragma omp parallel 
    {
        #pragma omp single
        {
            #pragma omp taskloop grainsize(2)
            for (int i = 0; i < N; i++) {
                printf("Hi from iteration %d, on thread %d\n", i, omp_get_thread_num());
            }
        }
    }
    return 0;
}