CC = g++
CCFLAGS = -Wall
PRJ = quantum
OBJS = main.o
HEAD = 

## targets and prerequisites

$(PRJ): $(OBJS)             ## next line must begin with a TAB
		$(CC) $(OBJS) -o $(PRJ) 
		
		./quantum

# rule for compiling .cc to .o
%.o : %.cc                  ## next line must begin with a TAB
		$(CC) -c $(CCFLAGS) $< 

$(OBJS):$(HEAD)             ## no executable, the previous rule is used



.PHONY: clean
clean:                      ## next lines must begin with a TAB
		rm -f $(OBJS) $(PRJ)
		rm -f *~ *% *# .#*