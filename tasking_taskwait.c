#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task 
            {
                for (int i = 0; i < 5; i++) {
                    #pragma omp task 
                    {
                        printf(" [Child %d, in %d] ", i, omp_get_thread_num());
                        for (int j = 0; j < 10; j++) {
                            #pragma omp task
                            { printf(" [Descend %d, of %i, in %d] ", j, i, omp_get_thread_num()); }
                        }
                    }
                }
                #pragma omp taskwait
                printf("\n\n-- And we are done here! -- \n\n");
            }
        }
    }
    printf("\n");
    return 0;
}