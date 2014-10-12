/*
 * Node.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: visio
 */

#include "Node.h"
#include "NodeManager.h"

namespace GT {

Node::Node(NodeManager* _manager, nodeID nodeId) {
	// TODO Auto-generated constructor stub
	id = nodeId;
	work = false;
	manager = _manager;
	manager->addNode(this);
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

bool Node::operator==(Node* n){
	if(n->getID() == id)
		return true;
	return false;
}

unsigned int Node::getID(){
		return id;
}

void Node::addMessageCode(unsigned int msgType){
		msgCodes.push_back(msgType);
}


void Node::handleMessages(){
		onCreate();

		while(work){ // TODO doplnit atribut work
			std::unique_lock<std::mutex> ulock(nodeMutex);

			if(msgList.empty())
				cond_var.wait(ulock);

			NodeMessage* nmsg = msgList.front();
			msgList.pop_front();
			ulock.unlock();
			execute(msgList.front());
		}

		onEnd();
}

void Node::addMsg(NodeMessage* msg){
		// Kriticka cast. Treba synchro?
		std::unique_lock<std::mutex> ulock(nodeMutex);
		printf("Pridana sprava: %s \n", msg->msgText.c_str());
		msgList.push_back(msg);
		wakeUp();
}

void Node::wakeUp(){
		cond_var.notify_one();
}

void Node::run(){
		work = true;
		nodeThread = std::thread(&Node::handleMessages, this);
}

void Node::stop(){
		work = false;
		nodeThread.join();
}

void Node::request(NodeMessage* msg){
	manager->sendMsg(msg);
	//manager->
	//manager->sendMsg(msg);
}

} /* namespace GT */
