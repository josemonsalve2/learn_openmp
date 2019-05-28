#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Taskgraph
//     OP1
//    /   \ 
//  OP2    OP3
//    \   /
//     OP4


int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    int res = 0;
    #pragma omp parallel 
    {
        #pragma omp single
        {
            // OP1
            #pragma omp task depend(out:x)
            {
                x = 10;
            }
            // OP2
            #pragma omp task depend(in:x) depend(out:y)
            {
                y = x + 20;
            }
            // OP3
            #pragma omp task depend(in:x) depend(out:z)
            {
                z = 2*x;
            }
            // OP4
            #pragma omp task depend(in:z,y)
            {
                res = y + z;
            }
        }
    }
    printf("res = %d\n", res); // res = (10 + 20) + (10 * 2)
    return 0;
}