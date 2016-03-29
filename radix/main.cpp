#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

#include <vector>
#include <iostream>

#include <omp.h>


using namespace std;

#ifndef ELM
#define ELM 32*1024*1024
#endif
#define STRIDE 3 // log order
#define M 0xff // 256 - 8bit uchar


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

unsigned int mem[ELM] = {0};
vector<unsigned int> bucket[M+1];

/**********************************************************************/
void data_init(char type[], unsigned int* mem) {
 int i;
 
 if (!strcmp(type, "random"))  for (i = 0; i < ELM; i++) mem[i] = xorshift();
 else if (!strcmp(type, "sorted"))  for (i = 0; i < ELM; i++) mem[i] = i;
 else if (!strcmp(type, "reverse")) for (i = 0; i < ELM; i++) mem[i] = ELM - 1 - i;
 else                               { printf("data_init type is wrong.\n"); exit(1); };
}

void print_array(void){
  for(int i = 0;i<ELM-1;i++){
    printf("%u,", mem[i]);
  }
  printf("%u\n", mem[ELM-1]);
}


void generate_bucket(void){
  for(int i=0;i<=M;i++){
    vector<unsigned int> a;
    bucket[i] = a;
  }
}

void _bucket_sort(unsigned int k){
int bn[M] = {0}; // How much ints is in the bucket?

  if(k==0){
    for(int i=0;i<ELM;i++){
      bucket[mem[i] & M].push_back(mem[i]);
    }
  } else {
    int shift = (k << STRIDE);
    for (int b=0;b<=M;b++){
      bn[b] = bucket[b].size();
      //printf("k=%u, bn[%d] = %d\n", k, b, bn[b]);
    }
    int b;
    //#pragma omp parallel for private(b, i)
    for(b=0;b<=M;b++){
      int i;
      for(i=0;i<bn[b];i++){
        unsigned int ai  = (bucket[b])[i];
        //bucket[b].pop_front();
        unsigned int idx = (ai >> shift) & M;
        bucket[idx].push_back(ai);
      }
      bucket[b].erase(bucket[b].begin(), bucket[b].begin() + bn[b]);
    }
    //for(b=0;b<=M;i++){
    //}
  }
}

void ret_bucket(){
  int n = 0;
  for(int b=0;b<=M;b++){
    int j = 0;
    for(j=0;j<(bucket[b]).size();j++){
      mem[n] = (bucket[b])[j];
      n++;
    }
    bucket[b].erase(bucket[b].begin(), bucket[b].begin() + j);
  }
}
  

void radix_sort(){
  for(int i=0;i<4;i++){
    _bucket_sort(i);
  }
  ret_bucket();
  
}

long time_diff_us(struct timeval st, struct timeval et)
{
    return (et.tv_sec-st.tv_sec)*1000000+(et.tv_usec-st.tv_usec);
}

int main(){
  struct timeval st, et;
  generate_bucket();
  char type [16] = "random";
  data_init(type, mem);
  //print_array();
  //bucket[0].push_back(2);
  gettimeofday(&st, NULL);
  radix_sort();
  gettimeofday(&et, NULL);
  printf("%ld, ", time_diff_us(st,et));
  //print_array();
  //bucket_sort(8);
  return 0;
}
  

// C++ implementation of Radix Sort

