
CFLAGS   = -Wall -Wextra
CPPFLAGS = -mkl
LDFLAGS  =
LIBS     =
CXX      = icpc


all: testm gause

gause: gause.c get_x.o clock.o
	$(CXX) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o gause gause.c get_x.o clock.o 

testm: testm.c get_x.o
	$(CXX) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o testm testm.c get_x.o

clock.o: clock.c clock.h
	$(CXX) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -c clock.c

get_x.o: get_x.c get_x.h
	$(CXX) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -c get_x.c

clean:
	rm -f testm gause *.o
