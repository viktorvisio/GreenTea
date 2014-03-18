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


	ArrayStack<int> stack = ArrayStack<int>(10);

	stack.push(45);
	stack.push(98);
	stack.push(-44);
	stack.push(789);

	printf("T: %d\n", stack.pop());
	printf("T: %d\n", stack.pop());
	printf("T: %d\n", stack.pop());
	printf("T: %d\n", stack.pop());

	return 0;
}
