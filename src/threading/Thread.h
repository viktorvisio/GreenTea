/*
 * Thread.h
 *
 *  Created on: Jun 6, 2013
 *      Author: visio
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>
#include <vector>

namespace GT {

class Thread {
public:

	/**
	 * Run is called once after start.
	 * Override it to implement what's going to happen in new thread.
	 */
	 virtual void* run(){ return NULL;}

	 /**
	  * Starts new thread.
	  */
	 void start();
	 void stop();
	 /**
	  * Waits for thread to complete.
	  */
	 void* join();
	 void kill(int sig_number);

#ifdef THREAD_MANAGEMENT
	 static void joinAll();
	 static void killAll(int sig_number);
#endif
	Thread();
	virtual ~Thread();

private:

#ifdef THREAD_MANAGEMENT
	static std::vector<pthread_t> threads;
#endif
	static void* func(void* arg);
	pthread_t thread_id;

};



} /* namespace Metatron */
#endif /* THREAD_H_ */
