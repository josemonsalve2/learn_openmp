#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    #pragma omp parallel 
    {
        #pragma omp single
        {
            #pragma omp task // Not needed, but to be explicit
            {
                printf("I am T1\n");
                for (int i = 0; i < 5; i++) {
                    #pragma omp task // Childrens of T1
                    {
                        printf("  I am a children of T1\n");
                        if (i == 0) {
                            #pragma omp task // Descendent of T1 
                            { printf("    I am a descendent of T1\n"); }
                        }
                    }
                }
            }
        }
    }
    return 0;
}