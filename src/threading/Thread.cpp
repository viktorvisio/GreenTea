/*
 * Thread.cpp
 *
 *  Created on: Jun 6, 2013
 *      Author: visio
 */

#include "Thread.h"
#include <signal.h>
#include <cstdio>

namespace GT {

Thread::Thread() {
	thread_id = -1;
}

Thread::~Thread(){

}

void* Thread::join(){
		 void* ret;
		 pthread_join(thread_id,&ret);
		 return ret;
}

void Thread::start(){
	pthread_create(&thread_id, NULL, func, this);
	//Thread::threads.push_back(thread_id);
#ifdef THREAD_MANAGEMENT
	Thread::threads.push_back(thread_id);
#endif
}

void* Thread::func(void* arg){
	Thread* t = (Thread*) arg;
	return t->run();
}

#ifdef THREAD_MANAGEMENT
void Thread::joinAll(){
	for(std::vector<pthread_t>::iterator i = Thread::threads.begin();  i != Thread::threads.end(); i++){
		pthread_join((*i), NULL);
	}
	Thread::threads.clear();
}

void Thread::killAll(int sig_number){
	for(std::vector<pthread_t>::iterator i = Thread::threads.begin();  i != Thread::threads.end(); i++){
		pthread_kill((*i), sig_number);
	}

	Thread::threads.clear();
}

std::vector<pthread_t> Thread::threads;
#endif

void Thread::kill(int sig_number){
	pthread_kill(thread_id, sig_number);
}


void Thread::stop(){
}

}
