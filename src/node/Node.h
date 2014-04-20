/*
 * Node.h
 *
 *  Created on: Apr 4, 2014
 *      Author: visio
 */

#ifndef NODE_H_
#define NODE_H_

#include <list>

using namespace std;

namespace GT {

#define MSG_TYPE_REQUEST_DATA 0;
#define MSG_TYPE_SEND_DATA 1;

struct node_msg{
	int type;
	void* data; // ???
};



class Node {
private:
	list<node_msg*> msg_queue;
public:
	Node();
	virtual ~Node();

	void addMsg(node_msg* msg){
		msg_queue.push_back(msg);
		// Nieco ine? Synchronizacia?
	}

	//Input, Output?
	void handleMessages(){

	}

	void sendMsg(int type, void* data){

	}

	/**
		 * Pridava typy dat ktore je schopny Node spracovat.
		 */
	void addDataType(int dType){

	}


	void execute();
};

} /* namespace GT */
#endif /* NODE_H_ */
