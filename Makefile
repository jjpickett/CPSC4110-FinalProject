# Flags needed for all executables
CC = g++
CCFLAGS = -std=c++11 -Wall

## targets and prerequisites
.PHONY: all
all : test cnot toffoli deutsch

test : test.o Algorithms.o Utils.o ## next line must begin with a TAB
	$(CC) $^ -o $@


cnot : cnot.o Algorithms.o Utils.o ## next line must begin with a TAB
	$(CC) $^ -o $@

toffoli : toffoli.o Algorithms.o Utils.o         ## next line must begin with a TAB
	$(CC) $^ -o $@

deutsch : deutsch.o Algorithms.o Utils.o         ## next line must begin with a TAB
	$(CC) $^ -o $@
	
##./test									## UNCOMMENT AND TAB TO RUN IT
##./cnot									## UNCOMMENT AND TAB TO RUN IT
##./toffoli									## UNCOMMENT AND TAB TO RUN IT
	./deutsch									## UNCOMMENT AND TAB TO RUN IT

# default rule for compiling .cc to .o
%.o: %.cc                               ## next line must begin with a TAB
	$(CC) -c $(CCFLAGS) $< 

Algorithms.o : Algorithms.h    ## no executables, the previous rule is used
Utils.o : Utils.h
test.o : Algorithms.h Utils.h
cnot.o : Algorithms.h Utils.h
toffoli.o : Algorithms.h Utils.h
deutsch.o : Algorithms.h Utils.h

.PHONY: clean
clean:                 ## next lines must begin with a TAB
	rm -f *.o
	rm -f *~ *# .#*

.PHONY: clean-all
clean-all : clean      ## next line must begin with a TAB
	rm -f test cnot toffoli deutsch