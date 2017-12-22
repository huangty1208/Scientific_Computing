
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "clock.h"
#include "get_x.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <mkl.h>



// make matrix left hand side 

void mkAb(int n,double A[n][n],double b[n]){
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
		A[i][j]=cos(M_PI*i*j/n);
	}
	for(int i=0;i<n;i++) b[i]=i;
}


// calculate residual
void report(int n,double A[n][n],double x[n],double b[n]){
	double y[n];
	mkAb(n,A,b);
	multAx(n,y,A,x);
	double r=0;
	for(int i=0;i<n;i++){
		double t=y[i]-b[i];
		r+=t*t;
	}
	r=sqrt(r);
	printf("The residual |Ax-b|=%g.\n",r);
}


// calcualte the time required for Explicity implement 
double mysolve(int n){
	double A[n][n],b[n],x[n];
	mkAb(n,A,b);
	printf("\nSimple Gaussian elimination solver...\n");
	double *PLU[n];
	tic();
	PLUfact(n,A,PLU);
	PLUsolve(n,PLU,x,b);
	double t=toc();	
	printf("Elapsed time is %g seconds.\n",t);
	report(n,A,x,b);
	return t;
}

// calculate the time required for lapacke library
double lasolve(int n){
	double A[n][n],b[n],x[n];
	mkAb(n,A,b);
	printf("\nOptimized LAPACK solver...\n");
	int P[n];
	memcpy(x,b,sizeof(double)*n);
	tic();
	int info=LAPACKE_dgesv(LAPACK_COL_MAJOR,n,1,A[0],n,P,x,n);
	double t=toc();
	if(info) printf("Error:  LAPACKE_dgesv returned %d\n",info);
	printf("Elapsed time is %g seconds.\n",t);
	report(n,A,x,b);
	return t;
}


// rertrive the size of matrix from user
int main(){
	int n;
	printf("Enter the size of the matrix to benchmark:\n");
	(void)scanf("%d",&n);
	printf("\nSolving Ax=b where n=%d...\n",n);
	{
		/*	Increase storage limits so we can test
			with really large matrices */
		struct rlimit r;
		getrlimit(RLIMIT_STACK,&r);
		r.rlim_cur+=n*n*sizeof(double);
		setrlimit(RLIMIT_STACK,&r);
	}
	double t1=mysolve(n);
	double t2=lasolve(n);
	for(int k=0;k<2;k++){
		double t1n=mysolve(n);
		if(t1n<t1) t1=t1n;
		double t2n=lasolve(n);
		if(t2n<t2) t2=t2n;
	}
	double p=100*(t1-t2)/t2;
	printf("\nThe LAPACK routine is %g percent faster.\n",p);
	return 0;
}
