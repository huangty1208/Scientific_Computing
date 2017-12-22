#include "poly.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sys/time.h>
#include <sys/resource.h>
#include <string> 
#include <sstream>
#include <stdio.h> 
using namespace std;


// write function including gsl libraries to fir polynomial regression 
bool polynomialfit(int obs, int degree, 
		   double *dx, double *dy, double *store, double *resi) /* n, p */
{
  gsl_multifit_linear_workspace *ws;
  gsl_matrix *cov, *X;
  gsl_vector *y, *c, *r;
  double chisq;
 
  int i, j;
 
  X = gsl_matrix_alloc(obs, degree);
  y = gsl_vector_alloc(obs);
  c = gsl_vector_alloc(degree);
  r = gsl_vector_alloc(obs);
  cov = gsl_matrix_alloc(degree, degree);
 
  for(i=0; i < obs; i++) {
    for(j=0; j < degree; j++) {
      gsl_matrix_set(X, i, j, pow(dx[i], j));
    }
    gsl_vector_set(y, i, dy[i]);
  }
 
  ws = gsl_multifit_linear_alloc(obs, degree);
  gsl_multifit_linear(X, y, c, cov, &chisq, ws);
 
  /* store result ... */
  for(i=0; i < degree; i++)
  {
    store[i] = gsl_vector_get(c, i);
  }
 
  gsl_multifit_linear_residuals(X, y, c, r);
  for(j=0; j < obs; j++)
  {
    resi[j] = gsl_vector_get(r, j);
  }


  /*close the session and free memory */

  gsl_multifit_linear_free(ws);
  gsl_matrix_free(X);
  gsl_matrix_free(cov);
  gsl_vector_free(y);
  gsl_vector_free(c);
  return true; 

}

 
  // wtie a dfunction to get the value of xi in the interval of 0 and 1

  int xvector(int num, vector<double>& vx){

    double inc = 0;

    for(int k=0; k < num; k++) {
      vx.push_back(inc+k*(1.0/(num-1)));
      
    }
    return 0;
    


}

// use main function to 1: get the desired degree and 2 calculate the required time
 
int main()
{

  int DEGREE;
  cout << "Please enter an integer degree value: ";
  cin >> DEGREE;
  double coeff[DEGREE];

// read from input.dat
  ifstream file("input.dat");
  vector<double> a;


 // test file open
   if (file) {
        double value;
 
 // read the elements in the file into a vector
        while ( file >> value ) {
          a.push_back(value);
        }                                                                                                     // close the file  
   }
  
  
// propagate xi

   vector<double> b;
   xvector(a.size(),b);

//fir vector to polynomial library 

  double* x = &b[0];
  double* y = &a[0]; 


  int NP = a.size();

  double residual[a.size()];
 
  polynomialfit(NP, DEGREE, x, y, coeff, residual);
  
  // calculate elapsed time  

  int co = a.size();
  double g;
  double h;

  string str;          //The string
  str = "verireport.dat";      //str is temp as string


  ofstream myfile;
  myfile.open( str.c_str() );  
  for (int n=0 ; n < co ; n++ )  {     
  g = residual[n];    
  h = h+g*g;
  myfile << g << "\n";  }

  myfile.close(); 

  cout << "total sum of squares TSS is " << h << endl;
  cout << "residuals have been written to verireport.dat" << endl;

  return 0;


}

