

Gaussian Elimination and LAPACK


Purpose: 
Solve  a  simple  square  system  of  equations  using  Gaussian  elimination in two ways: 1) Explicity implement Gaussian elimination 2) use a third-partyscientific library to solve the problem. Show a comparison of computed solution to the systemto the analytical solution. Also compare the performance of implementation to that of the tpl’simplementation.


Instructions:

Run ./testm to test solution of direct implementation of partial pivoting compared to tpl LAPACKE. To modify the square matrix, modify the test.m file directly.    

Run ./gause and input the size of the matrix to compare the performance of implementation to that of the tpl’s implementation.


The performance comparison is listed below:
 

   Matrix Size      Increase in Performace with LAPACK
       50                         8.6 % 
      100                        22.4 %
      500                       114.3 %
     1000                       184.8 %
     5000                       492.7 %


References:

https://stackoverflow.com/questions/8478007/gauss-seidel-method-to-compute-3-systems-of-linear-equations
https://codereview.stackexchange.com/questions/88879/linear-system-solver-using-gauss-jordan-elimination



