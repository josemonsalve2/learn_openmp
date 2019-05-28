#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10

int main() {
    int x = 0;
    #pragma omp parallel 
    {
        #pragma omp atomic
        x++;
    }
    printf("The number of threads was = %d\n",x);
    return 0;
}