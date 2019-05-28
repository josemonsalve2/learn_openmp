#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    #pragma omp parallel 
    {
        #pragma omp master
        {
            #pragma omp task final(1)
            {
                int x = 10;
                for (int i = 0; i < 10; i++) {
                    #pragma omp task mergeable
                    {
                        x++;
                        printf("(mergeable %d) Hi from %d\n", i, omp_get_thread_num());
                    }
                }
                printf("The value of x could be between 10 or 20 and it is %d \n", x);
            }
        }
    }
    return 0;
}