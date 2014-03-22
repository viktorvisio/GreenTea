/*
 * Stack.h
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */

#ifndef STACK_H_
#define STACK_H_

#include "Exception.h"

namespace GT{

template<typename T>
class ArrayStack{
	T* array;
	int cap;
	int current; // TODO pridat size
	bool resizeStack;

	// TODO check this code
	void resize(int newCap){
		T* arrayn = new T[newCap];
		for(int n = 0; n < current; n++){
			arrayn[n] = array[n];
		}
		delete[] array;
		array = arrayn;
	}


public:
	ArrayStack(int capacity, bool res = false){
		cap = capacity;
		array = new T[cap];
		current = 0;

		resizeStack = res;
	}

	~ArrayStack(){
		delete[] array;
	}

	bool push(T data){
		if(current >= cap){
			if(resizeStack)
				resize(cap*2);
			else
				return false;
		}
		array[current] = data;
		++current;
		return true;
	}

	T	pop(){
		if(current < 0)
			throw Exception("ArrayStack: There is nothing to pop!");
		--current;

		return array[current];
	}

	int size(){
		return current;
	}
};

};

#endif /* STACK_H_ */
