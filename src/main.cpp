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
#include "math/minmax.h"
#include "math/Vector.h"
#include "node/NodeManager.h"
#include "node/Node.h"
#include "node/NodeMessage.h"

#include "gui/MainFrame.h"

struct kek{
	char name;
	std::string msg;
};

int kek_compare(const kek &a, const kek &b){
	if(a.name < b.name)
		return -1;
	else if(a.name == b.name)
		return 0;

	return 1;
}

int main(int argc, char** argv){

	/*
	Vector<int> vec(40);
	vec[1] = 456;

	Vector<int> vec2(40);

	Vector<int> tt = vec*vec2;


	printf("V: %d\n", vec[1]);
*/
	//GT::PairingHeap<kek> hrep = GT::PairingHeap<kek>(kek_compare);
/*
	GT::min(GT::func,0.0,8.1, 0.00000000000001);

	GT::PairingHeap<int>* heap = new GT::PairingHeap<int>();

	heap->add(0);
	heap->add(8);
	heap->add(13);
	heap->add(4);
	heap->add(-4);
*/
	/*
	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("T: %d %d\n", heap.pool(), heap.size());
	printf("\n\n\n\n");
	*/
/*
	delete heap;
	printf("\n\n\n\n");

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

*/

	GT::NodeManager man;

	GT::Node* node = new GT::Node(&man, 5);

	GT::NodeMessage* msg = new GT::NodeMessage();
	msg->setTarget(5);
	msg->msgText = "Uvodna sprava.";

	GT::NodeMessage* msg2 = new GT::NodeMessage();
	msg2->setTarget(5);
	msg2->msgText = "Dalsia sprava.";


	node->run();
//	node->wakeUp();

	man.sendMsg(msg);


	for(int t = 0; t < 10; t++)
		man.sendMsg(msg2);


	GT::MainFrame window = GT::MainFrame();
	//sleep(2);
	//printf("Test.");

	return window.run(argc,argv);
}
