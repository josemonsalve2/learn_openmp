#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 0; i < 19; i++)
            {
            // untied task
            #pragma omp task untied
            {
                printf("(untied %d) Hi from %d\n", i, omp_get_thread_num());
                #pragma omp taskyield
                printf("(untied %d) bye from %d\n", i, omp_get_thread_num());
            }
            // Tied task
            #pragma omp task 
            {
                printf("(tied %d) Hi from %d\n", i, omp_get_thread_num());
                #pragma omp taskyield
                printf("(tied %d) bye from %d\n", i, omp_get_thread_num());
            }
            }
            
            
        }
    }
    return 0;
}