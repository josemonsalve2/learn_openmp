#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int someCriticalWork (int printIt) {
    static int myVar = 0;
    if (printIt)
        printf("myVar = %d\n", myVar);
    else
        myVar++;    
}
int main() {

    #pragma omp parallel
    {
        printf("Hello, I am %d\n", omp_get_thread_num());
        #pragma omp critical
        {
            someCriticalWork(0);
        }
    }
    someCriticalWork(1);
    return 0;
}