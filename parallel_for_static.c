#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

    #pragma omp parallel for schedule(static,3)
    for (int i = 0; i < 6; i++) {
        printf("Hi from %d iteration %d \n", omp_get_thread_num(), i);
    }
    return 0;
}