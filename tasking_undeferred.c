#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    #pragma omp parallel 
    {
        #pragma omp master
        {
            for (int i = 0; i < 10; i++) {
                printf("creating task = %d\n", i);
                if (i == 5) {
                    #pragma omp task if(0)
                        printf("(undeferred %d) Hi from %d\n", i, omp_get_thread_num());
                } else {
                    #pragma omp task
                        printf("(deferred %d) Hi from %d\n", i, omp_get_thread_num());
                }
            }
        }
    }
    return 0;
}