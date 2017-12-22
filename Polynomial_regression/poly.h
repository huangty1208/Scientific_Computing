#ifndef _POLY_H
#define _POLY_H
#include <gsl/gsl_multifit.h>
#include <stdbool.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <iomanip>


bool polynomialfit(int obs, int degree, 
		   double *dx, double *dy, double *store); /* n, p */
#endif

