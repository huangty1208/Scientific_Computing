
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "get_x.h"

void Aprint(int n, double A[n][n]){
	for(int i=0;i<n;i++) {
		if(i==0) printf("A=[[");
		else printf("   [");
		for(int j=0;j<n;j++){
			printf("%g",A[i][j]);
			putchar(j==n-1?']':' ');
		}
		if(i==n-1) printf("]\n");
		else printf("\n");
	}
}

// Print a vector
void Xprint(int n, double x[n]){
	printf("[");
	for(int i=0;i<n;i++) {
		printf("%g%c",x[i],i==n-1?']':' ');
	}
	printf("\n");
}

// Print the U matrix in the PLU factorization
void Uprint(int n, double *PLU[n]){
	for(int i=0;i<n;i++) {
		if(i==0) printf("U=[[");
		else printf("   [");
		for(int j=0;j<n;j++){
			if(j>=i) printf("%g",PLU[i][j]);
			else printf("0");
			putchar(j==n-1?']':' ');
		}
		if(i==n-1) printf("]\n");
		else printf("\n");
	}
}

// Print the L matrix in the PLU factorization
void Lprint(int n, double *PLU[n]){
	for(int i=0;i<n;i++) {
		if(i==0) printf("L=[[");
		else printf("   [");
		for(int j=0;j<n;j++){
			if(j<i) printf("%g",PLU[i][j]);
			else if(j==i) printf("1");
			else printf("0");
			putchar(j==n-1?']':' ');
		}
		if(i==n-1) printf("]\n");
		else printf("\n");
	}
}

// Print the permutation matrix in the PLU factorization
void Pprint(int n, double *PLU[n]){
	double *A0=PLU[0];
	for(int i=1;i<n;i++) if(PLU[i]<A0) A0=PLU[i];
	/*  The row A0 in PLU with the smallest memory address 
		was originally the first row of the matrix A */
	for(int i=0;i<n;i++) {
		if(i==0) printf("P=[[");
		else printf("   [");
		for(int j=0;j<n;j++){
			if(PLU[j]-A0==i*n) printf("1");
			else printf("0");
			putchar(j==n-1?']':' ');
		}
		if(i==n-1) printf("]\n");
		else printf("\n");
	}
}

int main(){
	printf("Testing Gaussian Elimination Routines...\n\n");
	double A[4][4] = {
		{  30.6958,	 71.9111,  28.0867,  50.8285},
		{ -21.8004, -36.7679, -53.8605, -11.9057},
		{  1.2225,	 2.7187,   2.7229,   1.6558},
		{ -26.0216, -19.8725, -37.2790, -14.5540}};
	int n=sizeof(A[0])/sizeof(double);
	double C[n][n],b[n],x[n],y[n];
	memcpy(C,A,sizeof(A));
	Aprint(n,A);
	for(int i=0;i<n;i++) b[i]=i;
	printf("b="); Xprint(n,b);
	double *PLU[n];
	PLUfact(n,A,PLU);
	Lprint(n,PLU); Uprint(n,PLU); Pprint(n,PLU);
	PLUsolve(n,PLU,x,b);
	printf("x="); Xprint(n,x);
	multAx(n,y,C,x);
	printf("y="); Xprint(n,y);
	double r=0;
	for(int i=0;i<n;i++) {
		double t=y[i]-b[i];
		r+=t*t;
	}
	r=sqrt(r);
	printf("\nThe residual r=|Ax-b| is %g.\n",r);
	if(r<1.0e-12) {
		printf("PASSED!\n");
		return 0;
	}
	printf("FAILED!\n");
	return 1;
}
