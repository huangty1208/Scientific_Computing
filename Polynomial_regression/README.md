

  Polynomial regression of the air quality dataset
  

  Description:
 
  This application perform a simple polynomial regression onnobservations 
  by finding coefficients β0,β1,...,βp to a degree p polynomial such that each xi is closet to yi. 
  For the methods, analyse the performance and convergence for a range of polynomial degrees.
  For each method, plot the solution polynomial and the dataset together.



  Instrcution:
    
  run ./poly to get the coefficient β0,β1,...,βp using the direct method for the degree 
  of polynomial user specified in command prompt. This also time the performance.  
  The estimated value will be saved in a file called "report"+degree+"txt"
  ex. user input degree 1 -> report1.txt


  Input Options:
 
  This application read from the "input.dat" so to change the input data simply change the input.dat.
  This application accepts one dependent variable (yi) at this time so it is single column. 


  Performance analysis:

  See performance.txt


  Fit Visualization:  

  Plot the solution polynomial and the dataset together to illustrate howclose 
  they are using gnuplot script gnu.p and gnu1.p. The plots are saved as 
  output.png and output1.png.   

  
  Code Verification:
  run ./test to get the the difference between numerical solution and the 
  analytic solutionthe. The residuals will be written in verireport.dat. TTS will be shown.

 


   

   

