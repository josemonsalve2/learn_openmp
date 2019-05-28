#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    #pragma omp parallel 
    {
        #pragma omp single
        {
            for (int i = 0; i < 5; i++) {
            #pragma omp task 
                printf("Hi from %d\n",omp_get_thread_num());
            }
        }
    }
    return 0;
}