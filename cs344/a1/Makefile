# Make file format:
CC = - gcc -std=gnu99 -Wall 
exe_file = out
$(exe_file): assignment1_func.o out.o 
	$(CC) assignment1_func.o out.o  -o $(exe_file)
out.o: out.c
	$(CC) -c out.c
assignment1_func.o: assignment1_func.c
	$(CC) -c assignment1_func.c
clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean