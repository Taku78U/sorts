TYPE=random
# SIZE=256*1024
SIZE=32*1024*1024

.SUFFIXES: .o

all: 
	g++ -O3 -DELM=131072 -fopenmp -Wall -W main.cpp -o main_128K.o
	g++ -O3 -DELM=524288 -fopenmp -Wall -W main.cpp -o main_512K.o
	g++ -O3 -DELM=2097152 -fopenmp -Wall -W main.cpp -o main_2M.o
	g++ -O3 -DELM=8388608 -fopenmp -Wall -W main.cpp -o main_8M.o
	g++ -O3 -DELM=33554432 -fopenmp -Wall -W main.cpp -o main_32M.o
	g++ -O3 -DELM=134217728 -fopenmp -Wall -W main.cpp -o main_128M.o

SOURCE = $(wildcard *.c)
CNT128K := 50
CNT512K := 20
CNT2M := 10
CNT8M := 5
CNT32M := 5
CNT128M := 5
OBJS = $(wildcard *.o)

exs:
	./$(OBJS) random
 
run: 
	@for var in `seq 1 $(CNT128K)` ; do \
		./main_128K.o >> radix_128K.csv ;\
	done
	@for var in `seq 1 $(CNT512K)` ; do \
		./main_512K.o >> radix_512K.csv ;\
	done
	@for var in `seq 1 $(CNT2M)` ; do \
		./main_2M.o >> radix_2M.csv ;\
	done
	@for var in `seq 1 $(CNT8M)` ; do \
		./main_8M.o >> radix_8M.csv ;\
	done
	@for var in `seq 1 $(CNT32M)` ; do \
		./main_32M.o >> radix_32M.csv ;\
	done
	@for var in `seq 1 $(CNT128M)` ; do \
		./main_128M.o >> radix_128M.csv ;\
	done

clean:
	rm -f *.o
