/*
 * main.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */


#include "stdio.h"
#include "tools/macros.h"
#include "structures/PairingHeap.h"
#include "structures/ArrayStack.h"
#include "tools/mergesort.h"

int main(){


	printf("Test\n");

	PRINT_ERROR("zla alokacia");

	/*
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

	*/
	GT::ArrayStack<int> stack = GT::ArrayStack<int>(10);

	stack.push(45);
	stack.push(98);
	stack.push(-44);
	stack.push(789);

	DEBUG_TRY_START
		printf("T: %d\n", stack.pop());
		printf("T: %d\n", stack.pop());
		printf("T: %d\n", stack.pop());
		printf("T: %d\n", stack.pop());
		printf("T: %d\n", stack.pop());
		printf("T: %d\n", stack.pop());
		//printf("T: %d\n", stack.pop());
	DEBUG_TRY_STOP

	int gt[] = {156,100,845,-41};
	GT::merge_sort<int>(gt, 4, &GT::int_comparator);

	FOR(0,4,n)
		printf("%d\n",gt[n]);

	return 0;
}
