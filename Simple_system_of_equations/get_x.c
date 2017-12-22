
#include <math.h>
#include "get_x.h"

// Make PLU factorization of matrix A
void PLUfact(int n, double A[n][n], double *PLU[n]){
	for(int i=0;i<n;i++) PLU[i]=A[i];
	for(int j=0;j<n;j++){
		for(int i=j+1;i<n;i++){
			if(fabs(PLU[j][j])<fabs(PLU[i][j])) {
				double *t=PLU[i]; PLU[i]=PLU[j]; PLU[j]=t;
			}
		}
		for(int i=j+1;i<n;i++){
			double r=PLU[i][j]/PLU[j][j];
			for(int k=j;k<n;k++) PLU[i][k]-=r*PLU[j][k];
			PLU[i][j]=r;
		}
	}
}

// Solve PLU x = b using back substitution
void PLUsolve(int n, double *PLU[n], double x[n], double b[n]){
	double *A0=PLU[0];
	for(int i=1;i<n;i++) if(PLU[i]<A0) A0=PLU[i];
	/*	The row with the smallest memory address 
		was the first row of the original matrix */
	for(int i=0;i<n;i++) x[i]=b[(PLU[i]-A0)/n];
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++) x[i]-=PLU[i][j]*x[j];
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++) x[i]-=PLU[i][j]*x[j];
		x[i]/=PLU[i][i];
	}
}

// Multiply A x and return the result as y
void multAx(int n,double y[n], double A[n][n], double x[n]){
	for(int i=0;i<n;i++) y[i]=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		y[i]+=A[i][j]*x[j];
	}
}
