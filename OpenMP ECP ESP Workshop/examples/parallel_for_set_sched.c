#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    // Guided
    printf("Guided schedule\n");
    omp_set_schedule(omp_sched_guided, 3);
    #pragma omp parallel for schedule(runtime)
    for (int i = 0; i < 6; i++) {
        printf("Hi from %d iteration %d \n", omp_get_thread_num(), i);
    }
    // Static
    printf("Static schedule\n");
    omp_set_schedule(omp_sched_static, 3);
    #pragma omp parallel for schedule(runtime)
    for (int i = 0; i < 6; i++) {
        printf("Hi from %d iteration %d \n", omp_get_thread_num(), i);
    }
    // Dynamic
    printf("Dynamic schedule\n");
    omp_set_schedule(omp_sched_dynamic, 3);
    #pragma omp parallel for schedule(runtime)
    for (int i = 0; i < 6; i++) {
        printf("Hi from %d iteration %d \n", omp_get_thread_num(), i);
    }
    // Auto
    printf("Auto schedule\n");
    omp_set_schedule(omp_sched_auto, 3);
    #pragma omp parallel for schedule(runtime)
    for (int i = 0; i < 6; i++) {
        printf("Hi from %d iteration %d \n", omp_get_thread_num(), i);
    }

    return 0;
}