#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#include <iostream>
#include <string.h>

using namespace std;

#include "../initialize.h"

int sort(int *data, size_t n)
{
  size_t i, j;
  int pivot;

  if (n <= 1) {
    /* do nothing */
    return 0;
  }

  /* select a pivot */
  /* pivot must not be the minimum value in data[0]..data[n-1] */
  pivot = data[0];
  for (i = 1; i < n; i++) {
    if (data[i] > pivot) {
      pivot = data[i];
      break;
    }
    else if (data[i] < pivot) {
      break;
    }
  }

  if (i == n) {
    /* all values are same */
    return 0;
  }

  i = 0;
  j = n-1;
  while (1) {
    double tmp;
    while (data[i] < pivot)
      i++;

    while (data[j] >= pivot)
      j--;

    if (i >= j) break;

    /* swap */
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    i++;
    j--;
  }

  /* recursive call */
  sort(data, i);
  sort(data+i, n-i);

  return 0;
}

int sort1(int *data, size_t n)
{
  /* bubble sort */
  size_t i;
  size_t j;
  for (j = n; j > 1; j--) {
    for (i = 0; i < j-1; i++) {
      if (data[i] > data[i+1]) {
        double tmp;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }

  return 0;
}



int sort_r(int *data, size_t n, int threads)
{
  size_t i, j;
  int pivot;

  if (n <= 1) {
    /* do nothing */
    return 0;
  }

  /* select a pivot */
  /* pivot must not be the minimum value in data[0]..data[n-1] */
  pivot = data[0];
  for (i = 1; i < n; i++) {
    if (data[i] > pivot) {
      pivot = data[i];
      break;
    }
    else if (data[i] < pivot) {
      break;
    }
  }

  if (i == n) {
    /* all values are same */
    return 0;
  }

  i = 0;
  j = n-1;
  while (1) {
    int tmp;
    while (data[i] < pivot)
      i++;

    while (data[j] >= pivot)
      j--;

    if (i >= j) break;

    /* swap */
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    i++;
    j--;
  }

  /* recursive call */
  if(threads == 1){
    sort(data, i);
    sort(data+i, n-i);
  } else {
#pragma omp task firstprivate(i, threads)
    sort_r(data, i, threads/2);
#pragma omp task firstprivate(i, threads)
    sort_r(data+i, n-i, threads-threads/2);
  }
#pragma omp taskwait

  return 0;
}

int check(int *data, size_t n)
{
  size_t i;
  for (i = 0; i < n-1; i++) {
    if (data[i] > data[i+1]) {
      printf("Error: data[%d]=%d, data[%d]=%df\n",
             i, data[i], i+1, data[i+1]);
    }
  }
  return 0;
}

int main(int argc, char *argv[])
{
	char* threads_c;
	//char* d_c;
     if(argc<2){
       cerr << "Define more params" << endl;
       exit(1);
     }
     #ifdef _OPENMP
	threads_c = argv[2];
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
	int num_threads = atoi(threads_c);

  #ifdef _OPENMP
	omp_set_num_threads(num_threads);
  #endif

	int* mem;
	mem = init(elms);
  struct timeval st;
  struct timeval et;
  
  #ifdef _OPENMP
  if(num_threads < 9999) omp_set_num_threads(num_threads);
  #endif



  gettimeofday(&st, NULL); /* get start time */
  if(num_threads == 1)   sort(mem, elms);
  else {
  #ifdef _OPENMP
#pragma omp parallel //num_threads(threads)
  {
#pragma omp single
    sort_r(mem, elms, num_threads);
  }
  #else
  sort(mem, elms);
  #endif
  }
  gettimeofday(&et, NULL); /* get start time */
  long us = time_diff_us(st, et);
  check(mem, elms);
  //print(data, n);

  printf("%ld,", us);

    //}

  free(mem);

  return 0;
}
