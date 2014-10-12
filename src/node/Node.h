/*
 * Node.h
 *
 *  Created on: Apr 4, 2014
 *      Author: visio
 */

#ifndef NODE_H_
#define NODE_H_

#include <list>

#include "NodeMessage.h"
#include <thread>
#include <condition_variable>

using namespace std;


namespace GT {

typedef unsigned int nodeID;

class NodeManager;

#define MSG_TYPE_REQUEST_DATA 0;
#define MSG_TYPE_SEND_DATA 1;


class Node {
private:
	bool work;
	nodeID id; // Node ID.
	NodeManager* manager;
	std::list<NodeMessage*> msgList;
	std::list<int> msgCodes;
	std::string nodeName;
	std::thread nodeThread;
	std::mutex nodeMutex;
	std::condition_variable cond_var;

	void handleMessages();

public:
	Node(NodeManager* manager, nodeID _nodeId);
	virtual ~Node();

	void addMessageCode(nodeID msgType);
	void addMsg(NodeMessage* msg);
	void wakeUp();
	bool operator==(Node* n);
	unsigned int getID();
	void run();
	void stop();
	void request(NodeMessage* msg);
	void response();

	void addArgument(std::string name, int type){
	}

	virtual void onCreate(){}
	virtual void onEnd(){}
	virtual void execute(NodeMessage* msg){}; // bool pretoze sa spyta ci bola korektne poslana alebo nie.
};

} /* namespace GT */
#endif /* NODE_H_ */
