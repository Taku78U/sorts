#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "../initialize.h"

using namespace std;

// #define _WIN32_WINNT  0x0501
 //#define LOCATE_ABSORUTE

#define ELM (32*1024*1024)        // (32*1024*1024) -> 128MB
//int mem[ELM], mem2[ELM];                // global memory

int* temp;

/**********************************************************************/
void MergeSort(int* data, int left, int right) {

	if (left >= right) return;

	int mid, i, j, k;


	mid = (left + right) / 2;
	//#pragma omp task private (data, left, mid)
//#pragma omp task shared(data)
		MergeSort(data, left, mid);
//#pragma omp task shared(data)
		MergeSort(data, mid + 1, right);
//#pragma omp taskwait

		//#pragma omp task private (data, right, mid)
	for (i = left; i <= mid; i++)                temp[i] = data[i];
	for (i = mid + 1, j = right; i <= right; i++, j--) temp[i] = data[j];

	i = left;
	j = right;
	for (k = left; k <= right; k++) {
		if (temp[i] <= temp[j]) data[k] = temp[i++];
		else                    data[k] = temp[j--];
	}
}
/**********************************************************************/
void PMergeSort(int data[], int left, int right, int threads) {

	if (left >= right) return;

	int mid, i, j, k;


	mid = (left + right) / 2;
	if (threads == 1){
		MergeSort(data, left, right);
	}
	else{
#pragma omp parallel sections
	{
#pragma omp section
		PMergeSort(data, left, mid, threads / 2);
#pragma omp section
		PMergeSort(data, mid + 1, right, threads - threads / 2);
	}

	}
	//#pragma omp task private (data, left, mid)

	for (i = left; i <= mid; i++)                temp[i] = data[i];
	for (i = mid + 1, j = right; i <= right; i++, j--) temp[i] = data[j];

	i = left;
	j = right;
	for (k = left; k <= right; k++) {
		if (temp[i] <= temp[j]) data[k] = temp[i++];
		else                    data[k] = temp[j--];
	}
}

/**********************************************************************/
void PTMergeSort(int data[], int left, int right, int threads) {

	if (left >= right) return;

	int mid, i, j, k;

	int d = right - left;

	mid = (left + right) / 2;
	if (threads == 1){
	//if (d<400){
		MergeSort(data, left, right);
	}
	else{
#pragma omp task
		PTMergeSort(data, left, mid, threads / 2);
#pragma omp task
		PTMergeSort(data, mid + 1, right, threads - threads / 2);
#pragma omp taskwait
	}
	//#pragma omp task private (data, left, mid)

	for (i = left; i <= mid; i++)                temp[i] = data[i];
	for (i = mid + 1, j = right; i <= right; i++, j--) temp[i] = data[j];

	i = left;
	j = right;
	for (k = left; k <= right; k++) {
		if (temp[i] <= temp[j]) data[k] = temp[i++];
		else                    data[k] = temp[j--];
	}
}

/**************************************************************************/
int main(int argc, char** argv)
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

	int* mem;
	mem = init(elms);
  temp = (int*)calloc(elms, sizeof(double));
  struct timeval st;
  struct timeval et;
  
  #ifdef _OPENMP
  if(num_threads < 9999) omp_set_num_threads(num_threads);
  #endif


	init(elms);
	gettimeofday(&st, NULL);
  #ifdef _OPENMP
  if(num_threads > 2)
#pragma omp parallel //num_threads(num_threads)
	{
#pragma omp single
		PTMergeSort(mem, 0, elms - 1, num_threads);
	}
  else MergeSort(mem, 0, elms-1);
  #else
  MergeSort(mem, 0, elms-1);
  #endif
	gettimeofday(&et, NULL);
	printf("%ld,", time_diff_us(st, et));
  free(mem);
  free(temp);
	return 0;
}
/**************************************************************************/

