#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#include <string.h>
#include <climits>
#include <iostream>
#include "../initialize.h"

using namespace std;

void bitonicSort_r(int num, double *mem)
{

  if(((num - 1) & num) != 0)
     return;
 
  for(int block = 2; block <= num; block = block << 1) {
    for(int step = block / 2; step >= 1; step = step >> 1) {
      #pragma omp parallel for
      for(int idx = 0; idx < num; idx++) {
        int e = idx ^ step;
        if(e > idx) {
          double v1 = mem[idx];
          double v2 = mem[e];
          if((idx & block) != 0) {
            if(v1 < v2) {
              mem[e] = v1;
              mem[idx] = v2;
            }
          } else {
            if(v1 > v2) {
              mem[e] = v1;
              mem[idx] = v2;
            }
          }
        }
      }
    }
  }
}

void bitonicSort(int num, double *mem)
{

  if(((num - 1) & num) != 0)
     return;
 
  for(int block = 2; block <= num; block = block << 1) {
    for(int step = block / 2; step >= 1; step = step >> 1) {
      for(int idx = 0; idx < num; idx++) {
        int e = idx ^ step;
        if(e > idx) {
          double v1 = mem[idx];
          double v2 = mem[e];
          if((idx & block) != 0) {
            if(v1 < v2) {
              mem[e] = v1;
              mem[idx] = v2;
            }
          } else {
            if(v1 > v2) {
              mem[e] = v1;
              mem[idx] = v2;
            }
          }
        }
      }
    }
  }
}

int check(double *data, size_t n)
{
  size_t i;
  for (i = 0; i < n-1; i++) {
    if (data[i] > data[i+1]) {
      printf("Error: data[%d]=%.4lf, data[%d]=%.4lf\n",
             i, data[i], i+1, data[i+1]);
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  
  struct timeval st, et;
	//char* threads_c;
	//char* d_c;
     if(argc<3){
       cerr << "Define more params" << endl;
       exit(1);
     }
     #ifdef _OPENMP
	//threads_c = argv[2];
     #endif
	int elms = 0;
  
  if(!strcmp(argv[1], "128K")) elms = 128*1024;
  else if (!strcmp(argv[1], "512K")) elms = 512*1024;
  else if (!strcmp(argv[1], "2M")) elms = 2*1024*1024;
  else if (!strcmp(argv[1], "8M")) elms = 8*1024*1024;
  else if (!strcmp(argv[1], "32M")) elms = 32*1024*1024;
  else if (!strcmp(argv[1], "128M")) elms = 128*1024*1024;
  else{
    fprintf(stderr, "ELM is wrong.\n");
    exit(1);
  }
  
  int num_threads = atoi(argv[2]);

  #ifdef _OPENMP
  if(num_threads < 2048)
  omp_set_num_threads(num_threads);
  #endif

  double* mem = init_d(elms);
	gettimeofday(&st, NULL);
  if(num_threads==1) bitonicSort(elms, mem);
  else bitonicSort_r(elms, mem);
	gettimeofday(&et, NULL);
  check(mem, elms);
	printf("%ld,", time_diff_us(st, et));
  free(mem);
}
