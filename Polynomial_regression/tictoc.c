/*	tictoc.c -- Matlab style time reporting functions
	Written 2013 by Masakazu Gesho and Eric Olson */

#include <sys/time.h>

static double tic_time;

void tic() {
    struct timeval tp;
    gettimeofday(&tp,0);
    tic_time=(double) tp.tv_sec + (double) tp.tv_usec * 1.e-6;
}

double toc() {
    struct timeval tp;
    gettimeofday(&tp,0);
    return ((double) tp.tv_sec + (double) tp.tv_usec * 1.e-6)-tic_time;
}
