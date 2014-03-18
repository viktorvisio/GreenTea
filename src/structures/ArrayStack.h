/*
 * Stack.h
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */

#ifndef STACK_H_
#define STACK_H_

template<typename T>
class ArrayStack{
	T* array;
	int cap;
	int current;
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
		++current;
		array[current] = data;
		return true;
	}

	T	pop(){
		if(current < 0)
			return 0;

		T r = array[current];
		--current;

		return r;
	}
};


#endif /* STACK_H_ */
