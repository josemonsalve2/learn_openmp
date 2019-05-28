# ESP Training Series: Performance Tuning with OpenMP 4.5 and 5.0

Presented on June 18th 2019

https://www.eventbrite.com/e/esp-training-series-performance-tuning-with-openmp-45-and-50-registration-62171203744

## How to compile the examples 
If you have an OMP enabled compiler, you need to set up the CC=<comp> and CFLAGS=<omp_flags> flags. By default gcc is configured

Thenk you should just use the makefile. For example:

```
CC=gcc CFLAGS=-fopenmp make
```

Then you can run each example

## Copyright

Attribution only
