TYPE=random
# SIZE=256*1024
SIZE=32*1024*1024

.SUFFIXES: .o

all: 
	g++ -O3 -fopenmp -Wall -W main.cpp -o main.o

SOURCE = $(wildcard *.c)
OBJS = $(wildcard *.o)

exs:
	./$(OBJS) random
 
run: 
	# ./bubble $(TYPE)
	# ./selection $(TYPE)
	# ./insertion $(TYPE)
	./pmerge_t.o 96 $(TYPE)
	#./quick $(TYPE)

128K:
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128K $${var} >> main_128K.csv;\
	done
	@printf "\n" >> main_128K.csv

512K:
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 512K $${var} >> main_512K.csv;\
	done
	@printf "\n" >> main_512K.csv

2M:
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 2M $${var} >> main_2M.csv;\
	done
	@printf "\n" >> main_2M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 2M $${var} >> main_2M.csv;\
	done
	@printf "\n" >> main_2M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 2M $${var} >> main_2M.csv;\
	done
	@printf "\n" >> main_2M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 2M $${var} >> main_2M.csv;\
	done
	@printf "\n" >> main_2M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 2M $${var} >> main_2M.csv;\
	done
	@printf "\n" >> main_2M.csv

8M:
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 8M $${var} >> main_8M.csv;\
	done
	@printf "\n" >> main_8M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 8M $${var} >> main_8M.csv;\
	done
	@printf "\n" >> main_8M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 8M $${var} >> main_8M.csv;\
	done
	@printf "\n" >> main_8M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 8M $${var} >> main_8M.csv;\
	done
	@printf "\n" >> main_8M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 8M $${var} >> main_8M.csv;\
	done
	@printf "\n" >> main_8M.csv

32M:
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 32M $${var} >> main_32M.csv;\
	done
	@printf "\n" >> main_32M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 32M $${var} >> main_32M.csv;\
	done
	@printf "\n" >> main_32M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 32M $${var} >> main_32M.csv;\
	done
	@printf "\n" >> main_32M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 32M $${var} >> main_32M.csv;\
	done
	@printf "\n" >> main_32M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 32M $${var} >> main_32M.csv;\
	done

128M:
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128M $${var} >> main_128M.csv;\
	done
	@printf "\n" >> main_128M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128M $${var} >> main_128M.csv;\
	done
	@printf "\n" >> main_128M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128M $${var} >> main_128M.csv;\
	done
	@printf "\n" >> main_128M.csv

	@printf "\n" >> main_128M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128M $${var} >> main_128M.csv;\
	done
	@printf "\n" >> main_128M.csv

	@printf "\n" >> main_128M.csv
	@for var in 1 2 4 8 16 32 64 128 256 512 1024; do \
		./main.o 128M $${var} >> main_128M.csv;\
	done
	@printf "\n" >> main_128M.csv
	
usp:
	@for var in 128K 512K 2M 8M 32M 128M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M 8M 32M 128M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M 8M 32M 128M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M 8M 32M 128M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M 8M 32M 128M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K 2M;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in 128K 512K;do \
		./main.o $${var} 9999 >> main_usp.csv;\
	done
	@printf "\n" >> main_usp.csv
	@for var in `seq 1 30` ;do \
		./main.o 128K 9999 >> main_usp.csv ;\
		printf "\n" >> main_usp.csv ;\
	done

clean:
	rm -f *.o
