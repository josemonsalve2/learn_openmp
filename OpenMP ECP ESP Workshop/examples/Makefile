CC?=gcc
CFLAGS?=-fopenmp -g 

OBJ=parallel master single critical barrier \
	parallel_for parallel_for_static parallel_for_guided parallel_for_set_sched \
	parallel_share parallel_private parallel_firstprivate parallel_for_reduction \
	parallel_atomic tasking tasking_depend tasking_terminology tasking_untied \
	tasking_undeferred tasking_mergeable tasking_taskwait tasking_taskgroup \
	tasking_taskloop

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

%.exe: %.o
	${CC} ${CFLAGS} $< -o $@ 

.PHONY: all
all: ${OBJ:=.exe}

clean: 
	rm -f ${OBJ:=.exe} ${OBJ:=.o}
