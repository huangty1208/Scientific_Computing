#ifndef _SOLVEAX_H
#define _SOLVEAX_H

extern void PLUfact(int n, double A[n][n], double *PLU[n]);
extern void PLUsolve(int n, double *PLU[n], double x[n], double b[n]);
extern void multAx(int n,double y[n], double A[n][n], double x[n]);
 
#endif
