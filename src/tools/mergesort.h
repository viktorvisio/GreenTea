/*
 * mergesort.h
 *
 *  Created on: Mar 19, 2014
 *      Author: visio
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <string.h>

namespace GT{

template<typename T>
static void bottomUP(T* array, T* buffer, int left, int right, int end){
	int s1 = left;
	int s2 = right;

	for(int i = left; i < end; i++){

		if(s1 < right && ((array[s1] <= array[s2]) || (s2 >= end))){
			buffer[i] = array[s1];
			s1++;
		}
		else{
			buffer[i] = array[s2];
			s2++;
		}
	}
}

inline int min(int a, int b){
	if(a <= b)
		return a;
	else
		return b;
}

template<typename T>
static void merge_sort(T* array, T* buffer, int size){
	int width;

	for(width = 1;  width < size; width *=2){
		for(int n = 0; n < size; n += 2*width){
			bottomUP<T>(array, buffer, n, min(n+width, size), min(n+2*width, size));
		}
		memcpy(array, buffer, size*sizeof(int));
	}
}

template<typename T>
static void merge_sort(T* array, int size){
	T* buffer = new T[size];
	int width;

	for(width = 1;  width < size; width *=2){
		for(int n = 0; n < size; n += 2*width){
			bottomUP<T>(array, buffer, n, min(n+width, size), min(n+2*width, size));
		}
		memcpy(array, buffer, size*sizeof(int));
	}

	delete[] buffer;
}

static int int_comparator(const int &a, const int &b){
	if(a < b)
		return -1;
	else if(a > b)
		return 1;

	return 0;
}

template<typename T>
static void bottomUPcomp(T* array, T* buffer, int left, int right, int end, int (*com_func)(const T &a,const T &b)){
	int s1 = left;
	int s2 = right;

	for(int i = left; i < end; i++){
		if(s1 < right && ((com_func(array[s1], array[s2]) < 1) || (s2 >= end))){
			buffer[i] = array[s1];
			s1++;
		}
		else{
			buffer[i] = array[s2];
			s2++;
		}
	}
}

/**
 * Arrayed Merge sort with custom compare function. Buffer is dynamically allocated.
 */
template<typename T>
static void merge_sort(T* array, int size, int (*com_func)(const T &a,const T &b)){
	T* buffer = new T[size];
	int width;

	for(width = 1;  width < size; width *=2){
		for(int n = 0; n < size; n += 2*width){
			bottomUPcomp<T>(array, buffer, n, min(n+width, size), min(n+2*width, size), com_func);
		}
		memcpy(array, buffer, size*sizeof(T));
	}

	delete[] buffer;
}

template<typename T>
static void merge_sort(T* array, T* buffer, int size, int (*com_func)(const T &a,const T &b)){
	int width;

	for(width = 1;  width < size; width *=2){
		for(int n = 0; n < size; n += 2*width){
			bottomUPcomp<T>(array, buffer, n, min(n+width, size), min(n+2*width, size), com_func);
		}
		memcpy(array, buffer, size*sizeof(T));
	}

	//delete[] buffer;
}


template<typename T, typename H>
static void pairbottomUPcomp(T* array, H* pair_array, T* buffer, H* pair_buffer, int left, int right, int end, int (*com_func)(const T &a,const T &b)){
	int s1 = left;
	int s2 = right;

	for(int i = left; i < end; i++){
		if(s1 < right && ((com_func(array[s1], array[s2]) < 1) || (s2 >= end))){
			buffer[i] = array[s1];
			pair_buffer[i] = pair_array[s1];
			s1++;
		}
		else{
			pair_buffer[i] = pair_array[s2];
			buffer[i] = array[s2];
			s2++;
		}
	}


}

/**
 * Pair merge sort. Sorts one array and affects another.
 */
template<typename T, typename H>
void pair_merge_sort(T* array, H* pair_array, T* buffer, H* pair_buffer, int size, int (*com_func)(const T &a,const T &b)){
	int width;

	for(width = 1;  width < size; width *=2){
		for(int n = 0; n < size; n += 2*width){
			pairbottomUPcomp<T, H>(array, pair_array,buffer, pair_buffer, n, min(n+width, size), min(n+2*width, size), com_func);
		}
		memcpy(array, buffer, size*sizeof(T));
		memcpy(pair_array, pair_buffer, size*sizeof(H));
	}

}
};

#endif /* MERGESORT_H_ */
