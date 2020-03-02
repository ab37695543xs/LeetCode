all:
	gcc $(file) -g -o test.o
clean:
	rm -f *.o
	rm -rf *.dSYM
