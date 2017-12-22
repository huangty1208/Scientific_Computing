
# Gnuplot script file for plotting data in file "force.dat"


set terminal png size 800,600
set output 'output.png'

set title "Polynomial Fit with varying degrees" 
set xlabel "equally scaled time x "
set ylabel "absolute humidity y"
set xrange [0.0:1]
set yrange [0:3]
plot    "report0.dat" using 1:2 title 'Actual value' with lines, \
            "report1.dat" using 1:2 title 'degree 1' with lines, \
            "report2.dat" using 1:2 title 'degree 2' with lines, \
            "report3.dat" using 1:2 title 'degree 3' with lines, \
            "report4.dat" using 1:2 title 'degree 4' with lines, \
            "report5.dat" using 1:2 title 'degree 5' with lines, \
            "report6.dat" using 1:2 title 'degree 6' with lines, \
            "report7.dat" using 1:2 title 'degree 7' with lines, \
            "report8.dat" using 1:2 title 'degree 8' with lines, \
            "report9.dat" using 1:2 title 'degree 9' with lines, \
            "report10.dat" using 1:2 title 'degree 10' with lines
