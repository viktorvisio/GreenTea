/*
 * main.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */


#include "stdio.h"
#include "tools/macros.h"
#include "structures/PairingHeap.h"


int main(){


	printf("Test\n");

	PRINT_ERROR("zla alokacia");


	GT::PairingHeap<int> heap = GT::PairingHeap<int>();

	heap.add(0);
	heap.add(8);
	heap.add(13);
	heap.add(4);
	heap.add(-4);

	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("T: %d %d\n", heap.pool(), heap.size());

	return 0;
}
