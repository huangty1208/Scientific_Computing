
# Gnuplot script file for plotting data in file "force.dat"


set terminal png size 800,600
set output 'output1.png'

set title "Polynomial Fit with varying degrees"
set xlabel "equally scaled time x "
set ylabel "absolute humidity y"
set xrange [0.0:1]
set yrange [0:3]
plot    "report0.dat" using 1:2 title 'Actual value' with lines, \
            "report11.dat" using 1:2 title 'degree 11' with lines, \
            "report12.dat" using 1:2 title 'degree 12' with lines, \
            "report13.dat" using 1:2 title 'degree 13' with lines, \
            "report14.dat" using 1:2 title 'degree 14' with lines, \
            "report15.dat" using 1:2 title 'degree 15' with lines, \
            "report16.dat" using 1:2 title 'degree 16' with lines, \
            "report17.dat" using 1:2 title 'degree 17' with lines, \
            "report18.dat" using 1:2 title 'degree 18' with lines, \
            "report19.dat" using 1:2 title 'degree 19' with lines, \
            "report20.dat" using 1:2 title 'degree 20' with lines

