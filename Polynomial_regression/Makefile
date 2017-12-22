

CPPFLAGS = -Wall -Wextra -pg  
LDFLAGS  = -I/opt/apps/intel17/gsl/2.3/include -L/opt/apps/intel17/gsl/2.3/lib
LIBS     = -lgsl -lgslcblas
CXX      = g++

all: poly  
.PHONY: all

poly: poly.c poly.h tictoc.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o poly poly.c poly.h tictoc.o $(LIBS)

tictoc.o: tictoc.c tictoc.h
	$(CXX) -c tictoc.c

test: poly
	./poly

profile: gmon.out
	gprof poly gmon.out > profile.txt

check: test profile


coverage: poly poly.gcno poly.gcda
	gcov poly.c


.PHONY: clean
clean:
	rm -f poly

