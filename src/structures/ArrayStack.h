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
public:
	ArrayStack(int capacity){
		cap = capacity;
		array = new T[cap];
		current = 0;
	}

	~ArrayStack(){
		delete[] array;
	}

	bool push(T data){
		if(current >= cap){
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
