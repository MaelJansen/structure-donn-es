CC=gcc
CFLAGS=-Wall -Werror -O3 -DNDEBUG
#CFLAGS=-Wall -Werror -g

launch_bench: bench
	./bench | tee bench.csv

launch_test: test_rope
	./test_rope

test_rope: test_rope.o rope.o inner_string.o
rope.o: rope.h 
#inner_string.o: inner_string.h
bench: bench.o rope.o inner_string.o 

clean:
	-rm *.o
distclean: clean
	-rm bench