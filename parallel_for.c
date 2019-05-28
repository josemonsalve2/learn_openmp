#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

    #pragma omp parallel for
    for (int i = 0; i < 6; i++) {
        printf("Hi from %d iteration %d \n", omp_get_thread_num(), i);
    }
    return 0;
}