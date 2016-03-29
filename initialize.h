#include <sys/time.h>
#include <algorithm>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
/**********************************************************************/
#define SEED       1
int xorshift(void) {
	static unsigned int x = 123456789;
	static unsigned int y = 362436069;
	static unsigned int z = 521288629;
	static unsigned int w = 88675123 ^ SEED;
	unsigned int        t = x ^ (x << 11);

	x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)) & 0x7fffffff;
}

/**********************************************************************/
void data_init_d(double* mem, int elms) {
	int i;

  for (i = 0; i < elms; i++) mem[i] = xorshift()/((double)INT_MAX+1);
}

/**********************************************************************/
void data_init(int* mem, int elms) {
  int i;

  for (i = 0; i < elms; i++) mem[i] = xorshift();
}

int* init(int elms){
  
  int* mem;
  mem  = (int*)calloc(elms, sizeof(int));
  data_init(mem, elms);
  return mem;
}

double* init_d(int elms){

  double* mem;
  mem  = (double*)calloc(elms, sizeof(double));
  data_init_d(mem, elms);
  return mem;

}

long time_diff_us(struct timeval st, struct timeval et)
{
    return (et.tv_sec-st.tv_sec)*1000000+(et.tv_usec-st.tv_usec);
}

